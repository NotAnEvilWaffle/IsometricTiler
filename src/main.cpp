#include "Game.h"
#include "NAGGL/ResourceManager.h"
#include "NAGGL/Sprite.h"
#include "NAGGL/Texture.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <NAGGL/SpriteRenderer.h>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

int main() {

  glfwInit();
  GLFWwindow *window = glfwCreateWindow(800, 600, "Isometric Tiler", nullptr, nullptr);
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

  // Input::Instance().SetWindow(window);

  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  Game test(800, 600);

  test.Init();

  naggl::SpriteRenderer SpriteRenderer = naggl::SpriteRenderer();
  SpriteRenderer.InitRenderData(800, 600);

  naggl::ResourceManager::LoadTexture("textures/block.png", "block");

  naggl::Sprite sprite(naggl::ResourceManager::GetTexture("block"), {400, 300}, {500, 500}, 0);

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

    test.ProcessInput();
    test.Update(deltaTime);
    test.Render();

    SpriteRenderer.Draw(sprite);

    glfwSwapBuffers(window);
  }

  glfwTerminate();
  return 0;
}

void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}
