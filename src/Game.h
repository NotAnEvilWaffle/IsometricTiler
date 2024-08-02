#pragma once

#include "NAGGL/SpriteRenderer.h"
#include "World/World.h"
#include <memory>

class Game {
public:
  Game(unsigned int width, unsigned int height);
  ~Game(){};

  void Init();
  void ProcessInput();
  void Update(float dt);
  void Render();

private:
  std::unique_ptr<naggl::SpriteRenderer> spriteRenderer;
  World *world;
};
