/** 
 * @file parse_translational.c
 * @brief  This file contains YAML parsing functions for the translational.yaml 
 *          file
 *
 */

/**
 * YAML implementation Document 
 * ------------------------------
 * I am using the libyaml library for parsing the YAML.
 * Why libyaml? because Yocto already has libyaml package recipe :)
 * 
 * How does libyaml work?
 * ----------------------
 * It parses the YAML file line by line and generates events.
 * 
 * These events are specify what the YAML file contains.
 * For Example: 
 * At the start of the document the STREAM-START event will get 
 * generated.
 * At the start of the list the SEQUENCE-START event will get generated 
 * 
 * And so on so forth.
 * List of all the events in libyaml - 
 * https://github.com/yaml/libyaml/blob/master/include/yaml.h
 * Line 355, "typedef enum yaml_event_type_e"
 * 
 * Parsing the File 
 * -----------------
 * I have modified an existing code for our purpose 
 * Link to the original code - 
 * https://gist.github.com/meffie/89d106a86b81c579c2b2a1895ffa18b0#file-parse-c
 * 
 * The code flow is.
 * 1. Start parsing the YAML file 
 * 2. libyaml will generate events 
 * 3. Consume those events one by one 
 *    - Create a state machine using the switch cases 
 *    - Pass these events through the State Machine
 *    - Store the data at required states
 *    - Exit from the State machine when exit states are reached. 
 *    
 *    
 * The expected sequence of events is:
 *
 *    stream ::= STREAM-START document* STREAM-END
 *    document ::= DOCUMENT-START section* DOCUMENT-END
 *    section ::= MAPPING-START (key list) MAPPING-END
 *    list ::= SEQUENCE-START values* SEQUENCE-END
 *    values ::= MAPPING-START (key value)* MAPPING-END
 *    key = SCALAR
 *    value = SCALAR
 *
 * For example:
 *
 *    stream-start-event
 *      document-start-event
 *        mapping-start-event
 *          scalar-event={value="pin 1", length=4}
 *          mapping-start-event
 *               Got scalar (value i2c-details)
 *               Got scalar (value 1)
 *               Got scalar (value spi-details)
 *               Got scalar (value 2)
 *               Got scalar (value uart-details)
 *               Got scalar (value 4)
 *               Got scalar (value pwm-details)
 *               Got scalar (value 0)
 *          mapping-end-event
 *        mapping-end-event
 *      document-end-event
 *    stream-end-event
 *
 */

/*
 *#####################################################################
 *  Initialization block
 *  ---------------------
 *  This block contains initialization code for this particular file.
 *  It typically contains Includes, constants or global variables used
 *  throughout the file.
 *#####################################################################
 */

/* --- Standard Includes --- */
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <yaml.h>

/* --- Project Includes --- */
#include "parse_translational.h"

#define PATH "/etc/shunya/interfaces/translational.yaml"

/* YAML Parser states. */
enum state_value {
        START,
        ACCEPT_KEY,
        ACCEPT_VALUE,
        ACCEPT_SECTION,
        STOP,
        ERROR
};


/* Structure to implement the Parser */
struct trans_parser_state {
        /* Parser States */
        enum state_value state;
        /* Accepted Flag - Set to 1 when the value gets accepted*/
        uint8_t accepted;
        /* Error value */
        int8_t error;
        /* Variable to Store Key*/
        char *key;
        /* Variable to Store Value*/
        char *value;
        /* Variable to store the Pin Index value */
        uint8_t pindex;
};

/* Board is the representation of 64 Pins */
//static struct tPin board_pins[64];

/*
 *#####################################################################
 *  Process block
 *  -------------
 *  This block contains all the process code for the particular layer.
 *  It typically contains internal functions and external functions 
 *  which implement the functionalities of the respective layer.
 *#####################################################################
 */

/**
 * @brief      Stores data into the global data structure every time the value
 *              is parsed from the YAML file.
 *
 * @param[in]      key     The key in the YAML file
 * @param[in]      value   The value in the YAML file
 * @param[in]  sindex  The sindex Sensor index
 */
static void store_data (struct tPin board_pins[], char key[], char value[], uint8_t pindex) 
{
        int32_t bus_number;
        
        if (strcmp(key, "i2c-details") == 0) {
                 
                if(strcmp(value, "null") == 0) {
                        board_pins[pindex].i2c_bus_number = -1;
                } else {
                        sscanf(value, "%d", &bus_number);
                        board_pins[pindex].i2c_bus_number = bus_number;
                }
                board_pins[pindex].active = PIN_ACTIVE;

        } else if (strcmp(key, "spi-details") == 0) {

                if(strcmp(value, "null") == 0) {
                        board_pins[pindex].spi_bus_number = -1;
                } else {
                        sscanf(value, "%d", &bus_number);
                        board_pins[pindex].spi_bus_number = bus_number;
                }
                board_pins[pindex].active = PIN_ACTIVE;
        } else if (strcmp(key, "uart-details") == 0) {

                if(strcmp(value, "null") == 0) {
                        board_pins[pindex].uart_dev_name[0] = '\0';
                } else {
                        strcpy(board_pins[pindex].uart_dev_name,value);
                }
                board_pins[pindex].active = PIN_ACTIVE;
        } else if (strcmp(key, "pwm-details") == 0) {

                if(strcmp(value, "null") == 0) {
                       board_pins[pindex].pwm[0] = -1;
                       board_pins[pindex].pwm[1] = -1;
                } else {
                        int32_t t1, t2;
                        sscanf(value, "%d.%d", &t1, &t2);
                        board_pins[pindex].pwm[0] = t1;
                        board_pins[pindex].pwm[1] = t2;
                }
                board_pins[pindex].active = PIN_ACTIVE;
        } else {
                fprintf(stderr, "Ignoring unknown key: %s\n", key);
        }
}


/**
 * @brief      Consume events generated by the YAML parser 
 *
 * @param[in]  s  Parser state 
 * @param[in]  event  The event variable
 *
 * @return     Parser state
 */
static struct trans_parser_state consume_event(struct trans_parser_state s, 
                                                yaml_event_t event, struct tPin pins[])
{       
	/* Start with Accepted flag is zero*/
        s.accepted = 0;
	/* Check which state the parser is in*/
        switch (s.state) {
		
                case START:

			switch (event.type) {
			
                        	case YAML_MAPPING_START_EVENT:
					s.state = ACCEPT_SECTION;
					break;
			
                        	case YAML_SCALAR_EVENT:
					fprintf(stderr, "Ignoring unexpected scalar: %s\n",
							(char*)event.data.scalar.value);
					break;
			
                        	case YAML_SEQUENCE_START_EVENT:
					fprintf(stderr, "Unexpected sequence.\n");
					s.state = ERROR;
					break;
			
                        	case YAML_STREAM_END_EVENT: 
					s.state = STOP; 
					break;
			
                        	default:
					break;
			}
			break; /* case START :*/
                
                case ACCEPT_SECTION:

                        switch (event.type) {
                
                                case YAML_SCALAR_EVENT:
                
                                        if (strncmp((char*)event.data.scalar.value, "pin", 3) == 0) {
                                                
                                                int32_t index;
                                                char temp[8];
                                                sscanf((char*)event.data.scalar.value, "%s %d", temp, &index);
                                                s.pindex = index;
                                                s.state = ACCEPT_SECTION;

                                        } else {
                                                fprintf(stderr, "Unexpected scalar: %s\n",
                                                        (char*)event.data.scalar.value);
                                        s.state = ERROR;
                                        }
                
                                        break;

                                case YAML_MAPPING_START_EVENT:
                                        s.state = ACCEPT_KEY;
                                        break;

                                case YAML_MAPPING_END_EVENT:
                                        s.state = START;
                                        break;
                
                                default:
                                        fprintf(stderr, "Unexpected event while getting scalar: %d\n", event.type);
                                        s.state = ERROR;
                                        break;
                        }
                
                        break;  /* case ACCEPT_SECTION :*/

                case ACCEPT_KEY:
		
                	switch (event.type) {
		
                		case YAML_SCALAR_EVENT:
					s.key = strdup((char*)event.data.scalar.value);
					s.state = ACCEPT_VALUE;
					break;
		
                		case YAML_MAPPING_END_EVENT:
					s.state = ACCEPT_SECTION;
					break;
                
                                case YAML_STREAM_END_EVENT: 
                                        s.state = STOP; 
                                        break;
		
                		default:
					fprintf(stderr, "Unexpected event while getting key: %d\n",
							event.type);
					s.state = ERROR;
					break;
			}
			break; /* case ACCEPT_VALUES :*/
		
                case ACCEPT_VALUE:
		
                	switch (event.type) {
		                      
                		case YAML_SCALAR_EVENT:
					s.value = (char*)event.data.scalar.value;
                                        store_data(pins,s.key, s.value, s.pindex);
                                        s.accepted = 1;
					s.state = ACCEPT_KEY;
					break;
				default:
					fprintf(stderr, "Unexpected event while getting value: %d\n",
							event.type);
					s.state = ERROR;
					break;
			}
			break; /* case ACCEPT_VALUE :*/



                case ERROR:

		case STOP:
			break; /* case STOP :*/
	}
	return s;
}

/**
 * @brief      Parse the translational.yaml file
 *
 * @param[out]  pins  Data structure representing the pins
 *
 * @return     0 on SUCCESS and -1 on FAILURE
 */
int8_t parse_trans_file (struct tPin pins[], uint8_t size)
{

        FILE* fh = fopen(PATH, "r");
	
        yaml_parser_t parser;
	yaml_event_t event;
	
        struct trans_parser_state state = {.state=START, .accepted=0, .error=0, .pindex=0};

        /**
         * Initialize the parser state
         */
	yaml_parser_initialize(&parser);

        /**
         * Provide the parser input file 
         */
        yaml_parser_set_input_file(&parser, fh);

        /**
         * Read the YAML file line by line 
         * And generate events from the file
         */
	do {
                /**
                 * Parse the file line by line 
                 */
		if (!yaml_parser_parse(&parser, &event)) {
			goto error;
		}
                /**
                 * Consume the Event 
                 */
                state = consume_event(state, event, pins);
		if (state.state == ERROR) {
			goto error;
		}
                /**
                 * Once the even is consumed 
                 * Delete the event and move on to the next event.
                 */
		yaml_event_delete(&event);
        /**
         * Loop till we parse all the lines in the YAML file
         */
	} while (state.state != STOP);
        

        /* Delete the parser after we finish the parsing */
	yaml_parser_delete(&parser);

	return 0;

error:
        /* Error Case for the YAML parser */
	yaml_parser_delete(&parser);
	return -1;

}
