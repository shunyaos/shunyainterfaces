# Set the CMake minimum version
cmake_minimum_required(VERSION 3.5)

# Declare the Project version and code Language
project(shunyaInterfaces VERSION 2.0.0 LANGUAGES C)

# Set the Build Type to Release
# Ideally there should be more Build Types, but for now there is only one
set(CMAKE_BUILD_TYPE "Release")

# Set C Flags for the project
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -D_GNU_SOURCE ")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wformat=2 -Wall -Wextra -Winline -pipe")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")

# List all Source files
set(SRC_FILES
	src/functions/adv_mode.c
	src/functions/function.c
	src/functions/simple_mode.c
	src/peripherals/common/adv_mode.c
	src/peripherals/common/peripheral.c
	src/peripherals/common/simple_mode.c
	src/peripherals/sensor/pcf8591.c
	src/yaml/parse_config.c
	src/yaml/parse_translational.c
	src/dashboard/influxdb.c
	)

# Add Rule to create a Shared object Library
add_library(${PROJECT_NAME}_user SHARED ${SRC_FILES})

# Include directories while compiling the project
target_include_directories(${PROJECT_NAME}_user PRIVATE
	src/functions
	src/sensor
	src/peripherals/common
	include
	src/yaml
	)

# List all Header files
set(HDR_FILES
	include/adv_functions.h
	include/functions.h
	include/sensor_ids.h
	include/simple_functions.h
	include/pcf8591.h
	include/influxdbs.h
)


# Set the properties of the Shared object file
# The line below names the .so files.
set_target_properties(${PROJECT_NAME}_user PROPERTIES
	VERSION ${PROJECT_VERSION}
	SOVERSION 1)

# The line below is used to install the public header files for the library.
set_target_properties(${PROJECT_NAME}_user PROPERTIES PUBLIC_HEADER "${HDR_FILES}")

# Link libraries needed for the project.
target_link_libraries(${PROJECT_NAME}_user PUBLIC -lm -lyaml -lcurl )
target_link_libraries(${PROJECT_NAME}_user PUBLIC -lshunyaInterfaces_core)

# Global Install Directories
include(GNUInstallDirs)

# Set correct Install directories
install(TARGETS ${PROJECT_NAME}_user EXPORT ${PROJECT_NAME}_userConfig
	ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
	LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
