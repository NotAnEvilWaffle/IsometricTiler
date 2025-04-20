#include "Game.h"
#include "NAGGL/ResourceManager.h"
#include <iostream>

Game::Game(unsigned int width, unsigned int height) : keys() {
  spriteRenderer = std::make_unique<naggl::SpriteRenderer>();
  spriteRenderer->InitRenderData(width, height);

  Init();
  camera = new Camera({0.0f, 0.0f, 0.0f}, 100.0f);
  world = new World();
  world->GetChunk(0, 1);
  world->GetChunk(1, 0);
  world->GetChunk(0, 0);
}

void Game::Init() { naggl::ResourceManager::LoadTexture("textures/block.png", "block"); }

void Game::ProcessInput(float dt) {
  if (this->keys[GLFW_KEY_UP])
    camera->Move(Camera::Direction::UP, dt);
  if (this->keys[GLFW_KEY_DOWN])
    camera->Move(Camera::Direction::DOWN, dt);
  if (this->keys[GLFW_KEY_LEFT])
    camera->Move(Camera::Direction::LEFT, dt);
  if (this->keys[GLFW_KEY_RIGHT])
    camera->Move(Camera::Direction::RIGHT, dt);
}

void Game::Update(float dt) {
  std::cout << camera->position.x << " " << camera->position.y << " " << camera->position.z
            << std::endl;
}

void Game::Render() {
  spriteRenderer->SetViewMatrix(camera->GetViewMatrix());
  world->Draw(*spriteRenderer);
}
