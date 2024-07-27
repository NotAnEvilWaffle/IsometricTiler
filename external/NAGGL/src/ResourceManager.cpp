#include "ResourceManager.h"
#include <memory>
#include <unordered_map>
#include <utility>

namespace naggl {

  std::unordered_map<std::string, std::unique_ptr<Texture>> ResourceManager::Textures;

  const Texture *ResourceManager::LoadTexture(const std::string &texturePath, const std::string &textureName) {
    auto texture = std::make_unique<Texture>(texturePath);
    const Texture *texturePtr = texture.get();
    Textures[textureName] = std::move(texture);
    return texturePtr;
  }

  const Texture *ResourceManager::GetTexture(const std::string &name) {
    auto it = Textures.find(name);
    return it != Textures.end() ? it->second.get() : nullptr;
  }
} // namespace naggl
