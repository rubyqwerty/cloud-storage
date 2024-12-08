cmake_minimum_required(VERSION 3.5)
project(caching)

set(CMAKE_CXX_STANDARD 17)

find_package(Drogon REQUIRED)
find_package(fmt)

include_directories(..)
aux_source_directory(. SRC)

add_library(${PROJECT_NAME} STATIC ${SRC})

target_link_libraries(${PROJECT_NAME} PUBLIC Drogon::Drogon fmt::fmt)