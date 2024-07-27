#include "Texture.h"
#include <memory>
#include <iostream>
#include <stb_image.h>

namespace naggl {

  std::shared_ptr<Texture> Texture::Create(const std::string &filePath) { return std::make_shared<Texture>(filePath); }

  Texture::Texture(const std::string &filePath) {
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    int width, height, numChannels;
    unsigned char *data = stbi_load(filePath.c_str(), &width, &height, &numChannels, 0);
    if (data) {
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
      glGenerateMipmap(GL_TEXTURE_2D);
    } else {
      std::cout << "Failed to load texture: filePath" << std::endl;
    }

    stbi_image_free(data);

    glBindTexture(GL_TEXTURE_2D, 0);
  }

  Texture::~Texture() { glDeleteTextures(1, &texture); }

  void Texture::Bind(unsigned int texUnit) const {
    glActiveTexture(texUnit);
    glBindTexture(GL_TEXTURE_2D, texture);
  }
} // namespace naggl
