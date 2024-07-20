cmake_minimum_required(VERSION 3.10)

project(IsometricTiler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(external)
add_subdirectory(src)

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)


add_custom_command( TARGET IsometricTiler PRE_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/game_folder $<TARGET_FILE_DIR:IsometricTiler>)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC IsometricTilerSources)

