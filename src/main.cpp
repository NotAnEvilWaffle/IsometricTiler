#include "Game.h"
#include "NAGGL/Texture.h"
#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <NAGGL/SpriteRenderer.h>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);

Game *g_game = nullptr;

int main() {

  glfwInit();
  GLFWwindow *window = glfwCreateWindow(800, 600, "Isometric Tiler", nullptr, nullptr);
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
  glfwSetKeyCallback(window, key_callback);
  // Input::Instance().SetWindow(window);

  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  Game test(800, 600);
  g_game = &test;
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  float deltaTime = 0.0f;
  float lastFrame = 0.0f;

  while (!glfwWindowShouldClose(window)) {

    float currentFrame = glfwGetTime();

    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    glfwPollEvents();

    processInput(window);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    test.ProcessInput(deltaTime);
    test.Update(deltaTime);
    test.Render();

    glfwSwapBuffers(window);
  }

  glfwTerminate();
  return 0;
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode) {
  if (key >= 0 && key < 1024) {
    if (action == GLFW_PRESS)
      g_game->keys[key] = true;
    else if (action == GLFW_RELEASE)
      g_game->keys[key] = false;
  }
}

void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}
