#pragma once

#include "NAGGL/SpriteRenderer.h"
#include "World/World.h"
#include "Camera.h"
#include <GLFW/glfw3.h>
#include <memory>

class Game {
public:
  Game(unsigned int width, unsigned int height);
  ~Game(){};

  void Init();
  void ProcessInput(float dt);
  void Update(float dt);
  void Render();

  bool keys[1024];

private:
  std::unique_ptr<naggl::SpriteRenderer> spriteRenderer;
  World *world;
  Camera *camera;
};
