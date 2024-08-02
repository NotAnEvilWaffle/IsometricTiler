#pragma once

#include "Chunk.h"
#include "NAGGL/SpriteRenderer.h"
class World {
public:
  World();
  ~World(){};

  void Draw(naggl::SpriteRenderer &renderer);

private:
  Chunk chunk;
};
