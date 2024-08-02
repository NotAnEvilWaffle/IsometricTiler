#pragma once

#include "NAGGL/Sprite.h"
#include "NAGGL/SpriteRenderer.h"
#include "NAGGL/Texture.h"
#include <glm/common.hpp>
#include <glm/fwd.hpp>
#include <vector>

class Chunk {
public:
  Chunk(){};
  Chunk(glm::vec2 position);
  Chunk(Chunk &&other) = default;
  ~Chunk(){};

  void Draw(naggl::SpriteRenderer &renderer);

private:
  class Cell {
  public:
    Cell(unsigned int x, unsigned int y, const naggl::Texture *cellTexture);

    ~Cell(){};
    naggl::Sprite sprite;

  private:
    glm::ivec2 position;
  };

public:
  std::vector<std::vector<Cell>> cells;

private:
  glm::vec2 screenPosition;
  const glm::ivec2 chunkSize = {3, 3};
  const int cellSize = 100;
};
