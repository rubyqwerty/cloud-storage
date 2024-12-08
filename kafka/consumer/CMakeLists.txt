cmake_minimum_required(VERSION 3.5.0)
project(consumer)

find_package(fmt)
find_package(RdKafka REQUIRED)

include_directories(..)
set(SOURCES consumer.hpp consumer.cpp)
add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC RdKafka::rdkafka++ fmt::fmt)