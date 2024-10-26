cmake_minimum_required(VERSION 3.5.0)
project(producer)

include_directories(..)
find_package(fmt)

set(SOURCES producer.cpp)
add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC rdkafka++ fmt)