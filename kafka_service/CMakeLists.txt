cmake_minimum_required(VERSION 3.5)
project(kafka_client)

set(CMAKE_CXX_STANDARD 17)

find_package(Drogon CONFIG REQUIRED)
include_directories(..)
aux_source_directory(. SRC)


add_library(${PROJECT_NAME} STATIC ${SRC})

target_link_libraries(${PROJECT_NAME} Drogon::Drogon fmt producer consumer)