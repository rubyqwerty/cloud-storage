cmake_minimum_required(VERSION 3.5)
project(cloud-storage CXX)

list(APPEND Modules
    file_service
    user_service
    kafka/consumer
    kafka/producer
)

foreach(module ${Modules})
    message(STATUS "module: ${module}")
    add_subdirectory(${module})    
endforeach()