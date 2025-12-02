cmake_minimum_required(VERSION 3.27)

project(Arenaplay)

set(CMAKE_CXX_STANDARD 17)

# Archivos fuente
file(GLOB SRC
        "*.cpp"
        "*.h"
)

add_executable(Arenaplay ${SRC})
