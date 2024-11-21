//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef TILE_HPP
#define TILE_HPP
#include "Texture.hpp"
#include "InteractiveObject.hpp"
class Tile {
  Texture texture;
  bool isFloor;
  InteractiveObject object;
};
#endif //TILE_HPP
