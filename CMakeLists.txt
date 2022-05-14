#TODO: Clean this up & make it elegant - CS2022/05

cmake_minimum_required(VERSION 3.10)
#specify C params
set(CMAKE_C_COMPILER /usr/bin/clang-12)

# specify the C++ params
set(CMAKE_CXX_COMPILER /usr/bin/clang++-12)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#Name of Executable
set( SERVER_EXE Server )
# Where the "Simple" library is located
set ( SIMPLE_DIR ~/Development/C++/Libraries/Simple)
set (SIMPLE_TERMINAL_DIR ${SIMPLE_DIR}/IO/Terminal)
# set the project name
project(CaoS)

# Directories to interegate
include_directories(${PROJECT_SOURCE_DIR} ${SIMPLE_TERMINAL_DIR}/src /usr/include)

# Find the Simple Terminal Library
find_library(LIBTERMINAL SimpleANSITerminal DIRECTORY ${SIMPLE_TERMINAL_DIR})

# Executable to create
add_executable( ${SERVER_EXE}  src/main.cpp )

# Libraries to splice in
TARGET_LINK_LIBRARIES( ${SERVER_EXE}
                       ${LIBTERMINAL} )
