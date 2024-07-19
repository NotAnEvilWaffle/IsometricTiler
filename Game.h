#pragma once

class Game {
public:
  Game(unsigned int width, unsigned int height);
  ~Game(){};

  void Init();
  void ProcessInput();
  void Update(float dt);
  void Render();

private:
};
