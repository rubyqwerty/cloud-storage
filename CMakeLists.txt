cmake_minimum_required(VERSION 3.5)
project(cloud-storage CXX)

list(APPEND Modules
    caching_service
    kafka_service
    kafka/consumer
    kafka/producer
    file_service
    user_service
)

foreach(module ${Modules})
    message(STATUS "module: ${module}")
    add_subdirectory(${module})    
endforeach()