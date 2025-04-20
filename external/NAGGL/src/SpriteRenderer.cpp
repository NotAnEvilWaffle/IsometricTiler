#include "SpriteRenderer.h"
#include "Texture.h"
#include <memory>
#include <glm/gtc/matrix_transform.hpp>

namespace naggl {

  SpriteRenderer::SpriteRenderer() : viewMatrix(glm::mat4(1.0f)) {
    this->spriteShader = std::make_unique<Shader>("shaders/shader.vert", "shaders/shader.frag");
  }

  void SpriteRenderer::SetViewMatrix(const glm::mat4 &viewMatrix) { this->viewMatrix = viewMatrix; }

  void SpriteRenderer::Draw(const Sprite &sprite) const {
    this->spriteShader->Use();
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(sprite.GetPosition(), 0.0f));
    model = glm::rotate(model, glm::radians(sprite.GetAngle()), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, glm::vec3(sprite.GetScale(), 1.0f));

    this->spriteShader->SetMat4("view", viewMatrix);
    this->spriteShader->SetMat4("model", model);

    sprite.BindTexture(GL_TEXTURE0);

    glBindVertexArray(this->quadVAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
  }

  void SpriteRenderer::InitRenderData(unsigned int width, unsigned int height) {
    unsigned int VBO, EBO;

    this->spriteShader->Use();
    this->spriteShader->SetInt("image", 0);
    auto projection = glm::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f, -1.0f, 100.0f);
    this->spriteShader->SetMat4("projection", projection);

    // Set vertices such that origin is center of quad
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, 0.0f, // bottom-left
        0.5f,  -0.5f, 1.0f, 0.0f, // bottom-right
        0.5f,  0.5f,  1.0f, 1.0f, // top-right
        -0.5f, 0.5f,  0.0f, 1.0f  // top-left
    };

    // Counter Clock-wise winding order
    unsigned int indices[] = {0, 1, 2, 2, 3, 0};

    glGenVertexArrays(1, &this->quadVAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(this->quadVAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
  }
} // namespace naggl
