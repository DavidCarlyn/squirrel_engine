cmake_minimum_required(VERSION 3.0.0)
project(squirrel_engine VERSION 0.1.0)

include_directories(${PROJECT_NAME} PUBLIC src/include)
add_library(${PROJECT_NAME} src/engine.cpp)

add_subdirectory(dependencies/glfw)

target_include_directories(${PROJECT_NAME} 
    PUBLIC dependencies/glfw/include
)

target_link_directories(${PROJECT_NAME} 
    PUBLIC dependencies/glfw/src
)

target_link_libraries(${PROJECT_NAME} glfw)
