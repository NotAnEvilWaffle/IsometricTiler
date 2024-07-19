cmake_minimum_required(VERSION 3.10)

project(IsometricTiler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(libraries)


set(SOURCE_FILES glad.c main.cpp Game.cpp)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC GL dl glfw glm naggl)

message(STATUS "finished building project files")
