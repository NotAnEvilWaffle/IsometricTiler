#include "Input.h"

void Input::SetWindow(GLFWwindow *window) { this->window = window; }

bool Input::IsKeyPressed(int keyCode) { return (glfwGetKey(window, keyCode) == GLFW_PRESS); }
