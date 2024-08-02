#include "World.h"
#include "NAGGL/ResourceManager.h"
#include "NAGGL/SpriteRenderer.h"
#include "NAGGL/Texture.h"

World::World() : chunk({0, 0}) {}

void World::Draw(naggl::SpriteRenderer &renderer) { chunk.Draw(renderer); }
