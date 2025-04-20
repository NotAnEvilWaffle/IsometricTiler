#include "Chunk.h"
#include "NAGGL/ResourceManager.h"
#include "NAGGL/SpriteRenderer.h"
#include <vector>

Chunk::Chunk(glm::vec2 position) : screenPosition(position) {

  cells.resize(chunkSize.x);

  glm::vec2 chunkIsoCoords =
      GridToIsometricCoords(position.x, position.y, (float)chunkSize.x * (float)cellSize);

  for (int x = 0; x < chunkSize.x; x++) {
    cells[x].reserve(chunkSize.y);
    for (int y = 0; y < chunkSize.y; y++) {

      glm::vec2 isometricCellCoords = GridToIsometricCoords(x, y, cellSize);

      // Adjust by chunk position
      int cellX = chunkIsoCoords.x + isometricCellCoords.x + (cellSize * 0.5);
      int cellY = chunkIsoCoords.y + isometricCellCoords.y + (cellSize * 0.5);
      Cell newCell(cellX, cellY, naggl::ResourceManager::GetTexture("block"));
      cells[x].push_back(newCell);
      glm::uvec2 coords(x, y);
    }
  }
}

glm::vec2 Chunk::GridToIsometricCoords(float x, float y, float sizeOffset) {
  glm::vec2 coords;
  coords.x = (x * 0.5 * sizeOffset) + (y * -0.5 * sizeOffset);
  coords.y = (x * 0.25 * sizeOffset) + (y * 0.25 * sizeOffset);
  return coords;
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
