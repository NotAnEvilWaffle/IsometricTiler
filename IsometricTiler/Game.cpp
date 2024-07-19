#include "Game.h"

Game::Game(unsigned int width, unsigned int height) {
  spriteRenderer = std::make_unique<naggl::SpriteRenderer>();
  spriteRenderer->InitRenderData(width, height);
}

void Game::Init() {}

void Game::ProcessInput() {}

void Game::Update(float dt) {}

void Game::Render() {}
