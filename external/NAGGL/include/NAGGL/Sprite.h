#pragma once

#include <cmath>
#include <glm/glm.hpp>
#include <memory>
#include "Texture.h"

namespace naggl {

  class Sprite {

  public:
    Sprite() : texture(), position({0, 0}), scale({1, 1}), angle(0.0f){};

    Sprite(const std::shared_ptr<Texture> &texture) : texture(texture), position({0, 0}), scale({1, 1}), angle(0.0f){};

    Sprite(const std::shared_ptr<Texture> &texture, glm::vec2 position, glm::vec2 scale, float angle)
        : texture(texture), position(position), scale(scale), angle(angle){};

    Sprite(const Sprite &sprite)
        : texture(sprite.texture), position(sprite.position), scale(sprite.scale), angle(sprite.angle){};

    void BindTexture(int tex) const { texture->Bind(tex); }
    glm::vec2 GetPosition() const { return position; }
    glm::vec2 GetScale() const { return scale; }
    float GetAngle() const { return angle; }

    void SetPosition(glm::vec2 position) { this->position = position; }
    void SetScale(glm::vec2 scale) { this->scale = scale; }
    void SetAngle(float angle);
    void Rotate(float angle);

    ~Sprite(){};

  private:
    std::shared_ptr<Texture> texture;
    glm::vec2 position;
    glm::vec2 scale;
    float angle;
  };

} // namespace naggl
