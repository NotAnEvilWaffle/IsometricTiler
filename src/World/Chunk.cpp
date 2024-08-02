#include "Chunk.h"
#include "NAGGL/ResourceManager.h"
#include "NAGGL/SpriteRenderer.h"
#include <vector>

Chunk::Chunk(glm::vec2 position) : screenPosition(position) {

  cells.resize(chunkSize.x);

  for (int x = 0; x < chunkSize.x; x++) {
    cells[x].reserve(chunkSize.y);
    for (int y = 0; y < chunkSize.y; y++) {

      int cellX = (position.x * (chunkSize.x * cellSize)) + (x * cellSize) + (cellSize * 0.5);
      int cellY = (position.y * (chunkSize.y * cellSize)) + (y * cellSize) + (cellSize * 0.5);
      Cell newCell(cellX, cellY, naggl::ResourceManager::GetTexture("block"));
      cells[x].push_back(newCell);
      glm::uvec2 coords(x, y);
    }
  }
}

void Chunk::Draw(naggl::SpriteRenderer &renderer) {
  for (auto &x : cells) {
    for (auto &cell : x) {
      renderer.Draw(cell.sprite);
    }
  }
}

Chunk::Cell::Cell(unsigned int x, unsigned int y, const naggl::Texture *cellTexture)
    : position({x, y}), sprite(cellTexture) {
  sprite.SetPosition(position);
  sprite.SetScale({100.0f, 100.0f});
  sprite.SetAngle(0.0f);
}
