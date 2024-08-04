#include "World.h"
#include "NAGGL/ResourceManager.h"
#include "NAGGL/SpriteRenderer.h"
#include "NAGGL/Texture.h"

World::World() {}

void World::Draw(naggl::SpriteRenderer &renderer) {
  for (auto &chunkPair : chunks) {
    chunkPair.second.Draw(renderer);
  }
}

Chunk &World::GetChunk(int x, int y) {
  glm::ivec2 key(x, y);
  auto it = chunks.find(key);
  if (it == chunks.end()) {
    it = chunks.emplace(key, Chunk({x, y})).first;
  }
  return it->second;
}
