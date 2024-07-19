#pragma once

#include <string>
#include <memory>
#include <glm/glm.hpp>
#include <glad/glad.h>

namespace naggl {

  class Texture {

  private:
    unsigned int texture;
    unsigned int width;
    unsigned int height;

  public:
    Texture(const std::string &filePath);
    ~Texture();

    void Bind(unsigned int texId = GL_TEXTURE0) const;
    static std::shared_ptr<Texture> Create(const std::string &filePath);

    glm::vec2 GetSize() const { return {width, height}; }
  };

} // namespace naggl
