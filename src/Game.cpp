#include "Game.h"
#include "NAGGL/ResourceManager.h"

Game::Game(unsigned int width, unsigned int height) {
  spriteRenderer = std::make_unique<naggl::SpriteRenderer>();
  spriteRenderer->InitRenderData(width, height);

  Init();

  world = new World();
}

void Game::Init() { naggl::ResourceManager::LoadTexture("textures/block.png", "block"); }

void Game::ProcessInput() {}

void Game::Update(float dt) {}

void Game::Render() { world->Draw(*spriteRenderer); }
