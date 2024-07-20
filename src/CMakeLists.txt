add_library(IsometricTilerSources
  Game.cpp
  glad.c
)

target_link_libraries(IsometricTilerSources PUBLIC GL dl glfw glm naggl)

