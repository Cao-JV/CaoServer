cmake_minimum_required(VERSION 3.10)
#specify C params
set(CMAKE_C_COMPILER /usr/bin/clang-12)

# specify the C++ params
set(CMAKE_CXX_COMPILER /usr/bin/clang++-12)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the project name
project(CaoS)

# add the executable
include_directories(${PROJECT_SOURCE_DIR} /usr/include)
find_library(LIBTERMINAL SimpleANSITerminal DIRECTORY ./)

SET( SERVER_EXE Server )
# add the executable
add_executable( ${SERVER_EXE}  main.cpp )

TARGET_LINK_LIBRARIES( ${SERVER_EXE}
                       ${LIBTERMINAL} )
