project(test-cloud-storage)

add_executable(${PROJECT_NAME} test_main.cc)

include_directories(../)

set (Models 
    ../models/User.h 
    ../models/User.cc
      )

add_library(libmodels STATIC ${Models})
target_link_libraries(libmodels PRIVATE Drogon::Drogon)

target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon libmodels)
ParseAndAddDrogonTests(${PROJECT_NAME})