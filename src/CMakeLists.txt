add_library(IsometricTilerSources
  Game.cpp
  glad.c
  World/World.cpp
  World/Chunk.cpp
  Camera.cpp
)

target_link_libraries(IsometricTilerSources PUBLIC GL dl glfw glm naggl)

