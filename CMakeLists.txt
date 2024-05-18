cmake_minimum_required(VERSION 3.10)
project(00Y-C)

# Specify the C & C++ standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for header files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Libs)

# Add source files
set(SOURCES
    main.c
    CrossPlatform/memlib.c
    CrossPlatform/fslib.c
)

# Add the executable
add_executable(00Y-C ${SOURCES})

# Specify that this is a console application
if(WIN32)
    set_target_properties(00Y-C PROPERTIES LINK_FLAGS "-Wl,--subsystem,console")
endif()