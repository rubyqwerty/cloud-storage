cmake_minimum_required(VERSION 3.5)
project(user_service CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cc)

include_directories(..)

find_package(fmt)
find_package(Drogon CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} caching fmt::fmt kafka_client Drogon::Drogon  )

aux_source_directory(controllers CTL_SRC)
aux_source_directory(filters FILTER_SRC)
aux_source_directory(plugins PLUGIN_SRC)
aux_source_directory(models MODEL_SRC)

target_include_directories(${PROJECT_NAME}
                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
                                   ${CMAKE_CURRENT_SOURCE_DIR}/models)
target_sources(${PROJECT_NAME}
               PRIVATE
               ${SRC_DIR}
               ${CTL_SRC}
               ${FILTER_SRC}
               ${PLUGIN_SRC}
               ${MODEL_SRC})

file(COPY configs/config.docker.json configs/config.json DESTINATION ${CMAKE_BINARY_DIR}/user_service)

