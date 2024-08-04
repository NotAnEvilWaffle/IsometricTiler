#pragma once

#include "Chunk.h"
#include "NAGGL/SpriteRenderer.h"
#include <cstddef>
#include <glm/fwd.hpp>
#include <unordered_map>
#include <vector>

struct chunkHash {
  std::size_t operator()(const glm::ivec2 &v) const {
    auto hash1 = std::hash<int>{}(v.x);
    auto hash2 = std::hash<int>{}(v.y);
    return hash1 ^ (hash2 << 1);
  }
};

class World {
public:
  World();
  ~World(){};

  void Draw(naggl::SpriteRenderer &renderer);

  Chunk &GetChunk(int x, int y);

private:
  std::unordered_map<glm::ivec2, Chunk, chunkHash> chunks;
};
