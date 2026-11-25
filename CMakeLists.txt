cmake_minimum_required(VERSION 3.16)
project(vetamigo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# As classes ficam numa biblioteca; o programa só liga nela
add_library(vetamigo_lib STATIC
    src/animal.cpp
    src/cachorro.cpp
    src/gato.cpp
    src/coelho.cpp
)
target_include_directories(vetamigo_lib PUBLIC include)

# Portão de avisos da Unidade I, incidindo sobre a biblioteca
target_compile_options(vetamigo_lib PRIVATE
    -Wall -Wextra -Wpedantic -Wshadow -Wold-style-cast -Wcast-align
    -Wconversion -Wsign-conversion -Wnon-virtual-dtor -Wdouble-promotion
    -Wformat=2 -Werror
)

add_executable(vetamigo src/main.cpp)
target_link_libraries(vetamigo PRIVATE vetamigo_lib)