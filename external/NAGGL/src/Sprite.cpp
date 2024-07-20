#include "Sprite.h"
#include <cmath>

namespace naggl {

  void Sprite::SetAngle(float angle) {
    angle = std::remainder(angle, 360.0f);
    if (angle < 0)
      angle += 360.0f;

    this->angle = angle;
  }

  void Sprite::Rotate(float angle) { SetAngle(angle + this->angle); }
} // namespace naggl
