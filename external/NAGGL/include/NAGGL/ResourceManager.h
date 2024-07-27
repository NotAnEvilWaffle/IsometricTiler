#pragma once

#include <memory>
#include <unordered_map>
#include "Texture.h"

namespace naggl {
  class ResourceManager {
  public:
    // static std::map<std::string, Texture> Textures;
    static const Texture *LoadTexture(const std::string &texturePath, const std::string &textureName);
    static const Texture *GetTexture(const std::string &textureName);

  private:
    ResourceManager() {}

    static std::unordered_map<std::string, std::unique_ptr<Texture>> Textures;
  };
} // namespace naggl
