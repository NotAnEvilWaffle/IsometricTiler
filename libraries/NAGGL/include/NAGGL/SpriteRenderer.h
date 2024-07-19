#pragma once

#include "Shader.h"
#include "Sprite.h"
#include <memory>

namespace naggl {

  class SpriteRenderer {
  public:
    SpriteRenderer();
    ~SpriteRenderer(){};

    void Draw(const Sprite &sprite) const;
    void InitRenderData(unsigned int width, unsigned int height);

  private:
    std::unique_ptr<Shader> spriteShader;
    unsigned int quadVAO;
  };
} // namespace naggl
