//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef AREA_HPP
#define AREA_HPP
#include <Tile.hpp>
#include <vector>
#include "AreaType.hpp"

class Area {
    std::vector<std::vector<Tile>> tiles;
    std::vector<int> gatewayPositions;
    AreaType type;

public:
    Area(std::vector<std::vector<Tile>> fragments, std::vector<int> gatewayPositions, AreaType type);
};
#endif //AREA_HPP
