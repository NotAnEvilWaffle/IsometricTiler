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
    void SetViewMatrix(const glm::mat4 &viewMatrix);

  private:
    std::unique_ptr<Shader> spriteShader;
    unsigned int quadVAO;
    glm::mat4 viewMatrix;
  };
} // namespace naggl
