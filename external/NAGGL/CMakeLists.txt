project(naggl VERSION 0.1.0 DESCRIPTION "not a good game library")


set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external)

set(SOURCE_FILES
    ${SRC_DIR}/Input.cpp
    ${SRC_DIR}/Shader.cpp
    ${SRC_DIR}/Sprite.cpp
    ${SRC_DIR}/SpriteRenderer.cpp
    ${SRC_DIR}/Texture.cpp
    ${LIB_DIR}/stb_image/stb_image.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${LIB_DIR}/stb_image
        ${CMAKE_CURRENT_SOURCE_DIR}/include/NAGGL
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  )

target_link_libraries(${PROJECT_NAME} PUBLIC GL dl glfw glm)

message(STATUS "naggl library was built")
