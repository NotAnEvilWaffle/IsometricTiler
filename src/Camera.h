#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
  enum class Direction { UP, DOWN, LEFT, RIGHT };

  float panSpeed;

  glm::vec3 position, forward, right, up, worldUp;

  Camera(glm::vec3 position, float panSpeed);
  Camera(Camera &&) = default;
  Camera(const Camera &) = default;
  Camera &operator=(Camera &&) = default;
  Camera &operator=(const Camera &) = default;
  ~Camera();

  glm::mat4 GetViewMatrix();
  void Move(Direction direction, float deltaTime);

private:
};
