cmake_minimum_required(VERSION 3.10.2)

# set the project name
project(pendu)

include_directories(include)

set(SOURCES src/pendu.c
			 src/main.c)

# add the executable
add_executable(pendu
			${SOURCES})
