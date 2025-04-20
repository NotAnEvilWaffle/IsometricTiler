#include "Camera.h"

Camera::Camera(glm::vec3 position, float panSpeed)
    : position(position), forward(glm::vec3(0.0f, 0.0f, -1.0f)), up(glm::vec3(0.0f, 1.0f, 0.0f)),
      right(glm::vec3(1.0f, 0.0f, 0.0f)), panSpeed(panSpeed) {}

glm::mat4 Camera::GetViewMatrix() { return glm::lookAt(position, position + forward, up); }

void Camera::Move(Direction direction, float deltaTime) {
  float velocity = panSpeed * deltaTime;

  glm::vec3 screenRight = glm::vec3(1.0f, 0.0f, 0.0f);

  // Camera is moving in screenspace, so correct for up being -y and down being +y
  glm::vec3 screenUp = glm::vec3(0.0f, -1.0f, 0.0f);

  if (direction == Direction::UP)
    position += screenUp * velocity;
  if (direction == Direction::DOWN)
    position -= screenUp * velocity;
  if (direction == Direction::LEFT)
    position -= screenRight * velocity;
  if (direction == Direction::RIGHT)
    position += screenRight * velocity;
}
