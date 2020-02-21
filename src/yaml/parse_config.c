/** 
 * @file   parse_config.c
 * @brief  This file contains YAML parsing functions for the config.yaml file
 *
 *  The user will be using the config.yaml file to tell us the connections 
 *  that they made while connecting the sensors and actuators.
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
 *          scalar-event={value="pin1", length=4}
 *          scalar-event={value="null", length=4}
 *          scalar-event={value="pin1", length=4}
 *          scalar-event={value="null", length=4}
 *          scalar-event={value="pin1", length=4}
 *          scalar-event={value="null", length=4}
 *          scalar-event={value="pin1", length=4}
 *          scalar-event={value="null", length=4}
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
#include "parse_config.h"
/**
 * TODO : Error HANDLING
 */

#define PATH1 "config.yaml"
#define PATH_DEF "/etc/shunya/interfaces/config.yaml"

/* YAML Parser states. */
enum state_value {
        START,
        ACCEPT_KEY,
        ACCEPT_VALUE,
        ACCEPT_VALUES,
        STOP,
        ERROR,

};

/* Structure to implement the Parser */
static struct config_parser_state {
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
};

/* Board is the representation of 64 Pins */
//static struct cPin board_pins[64];
 
/* Variable to store the Sensor Index value */
static uint8_t sindex = 0;


/*
 *#####################################################################
 *  Process block
 *  -------------
 *  This block contains all the process code for the particular file.
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
static void store_data (struct cPin *pins, char key[], char value[], uint8_t sindex) {
        if (strncmp(key, "pin",3) == 0) {
                
                int32_t index;
                
                char temp[8];
                
                sscanf(key, "%s %d", temp, &index);

                if(strcmp(value, "null") == 0) {
                        pins[index].sensor[sindex].sensor_uid = -1;
                        pins[index].sensor[sindex].sensor_conid = -1;
                } else {
                        int32_t temp1;
                        int32_t temp2;

                        sscanf(value, "%d.%d", &temp1, &temp2);
                        pins[index].sensor[sindex].sensor_uid =  temp1;
                        pins[index].sensor[sindex].sensor_conid = temp2; 
                }
        }else {
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
static struct config_parser_state consume_event(struct config_parser_state s, 
						yaml_event_t event,
						struct cPin *pins)
{       
	/* Start with Accepted flag is zero*/
        s.accepted = 0;
	/* Check which state the parser is in*/
        switch (s.state) {
		
                case START:

			switch (event.type) {
			
                        	case YAML_MAPPING_START_EVENT:
					s.state = ACCEPT_KEY;
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
		
                case ACCEPT_KEY:
		
                	switch (event.type) {
		
                		case YAML_SCALAR_EVENT:
					s.key = strdup((char*)event.data.scalar.value);
					s.state = ACCEPT_VALUE;
                                        sindex = 0;
					break;
		
                		case YAML_MAPPING_END_EVENT:
					s.state = START;
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
                
                                case YAML_SEQUENCE_START_EVENT: 
                                        s.state = ACCEPT_VALUES; 
                                        break;
		
                		case YAML_SCALAR_EVENT:
					s.value = (char*)event.data.scalar.value;
                                        store_data(pins, s.key, s.value, sindex);
                                        s.accepted = 1;
					free(s.key);
					s.state = ACCEPT_KEY;
					break;
				default:
					fprintf(stderr, "Unexpected event while getting value: %d\n",
							event.type);
					s.state = ERROR;
					break;
			}
			break; /* case ACCEPT_VALUE :*/
                case ACCEPT_VALUES:
                        switch (event.type) {
                                case YAML_SCALAR_EVENT:
                                        s.value = (char*)event.data.scalar.value;
                                        
                                        store_data(pins, s.key, s.value, sindex);
                                        s.accepted = 1;
					sindex++; 
                                        break;
                                
                                case YAML_MAPPING_START_EVENT:
                                        s.state = ACCEPT_KEY;
                                        break;
                                
                                case YAML_SEQUENCE_END_EVENT: 
                                        s.state = ACCEPT_KEY; 
                                        break;
                                
                                case YAML_DOCUMENT_END_EVENT: 
                                        s.state = START; 
                                        break;
                                
                                default:
                                        fprintf(stderr, "Unexpected event while getting mapped values: %d\n",
                                        event.type);
                                        s.state = ERROR;
                                        break;

                        }
                break; /* case ACCEPT_VALUES :*/

                case ERROR:

		case STOP:
			break; /* case STOP :*/
	}   
	return s;
}

/**
 * @brief      Parse the Config.yaml file
 *
 * @param[out] pins  data structure representing pins
 *
 * @return     0 on SUCCESS and -1 on FAILURE
 */
int8_t parse_config_file (struct cPin *pins, uint8_t size)
{

        /* Variable to set return value */
        int8_t ret = -1;

        FILE* fh = fopen(PATH1, "r");

        /* Some times the Config file might not exist 
         * in the same directory 
         * Hence if this fails then use the config file in
         * /etc/interfaces/config.yaml
         */
        if (fh == NULL) {
                /* Use the config file in /etc/interfaces/config.yaml */
                fh = fopen(PATH_DEF, "r"); 
        }

        /* Libyaml variables */
        yaml_parser_t parser;
	yaml_event_t event;
	
        struct config_parser_state state = {.state=START, .accepted=0, .error=0};

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
			/* Error state */
                        ret = -1;
                        break;
		}
                /**
                 * Consume the Event 
                 */
                state = consume_event(state, event, pins);
		if (state.state == ERROR) {
                        /* Error state */
                        ret = -1;
                        break;
		}
                /**
                 * Once the even is consumed 
                 * Delete the event and move on to the next event.
                 */
		yaml_event_delete(&event);

                /* All OK return 0 */ 
                ret = 0;
        /**
         * Loop till we parse all the lines in the YAML file
         */
	} while (state.state != STOP);

        /* Delete the parser after we finish the parsing */
	yaml_parser_delete(&parser);

	return ret;

}

