//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef TILE_HPP
#define TILE_HPP
#include "Texture.hpp"
#include "InterractiveObject.hpp"
class Tile {
  Texture texture;
  bool isFloor;
  InterractiveObject object;
};
#endif //TILE_HPP
