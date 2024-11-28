//
// Created by Enzo Renard on 19/11/2024.
//
#include <random>
#include "Area.hpp"

#include <Areas.hpp>

Area Area::getRandomArea() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, DefinedAreas::size());
    return DefinedAreas::get(static_cast<Areas>(dis(gen))).area;
}

Area::Area() : type(OUTSIDE) {
}

Area::Area(std::vector<std::vector<Tile>> tiles, std::vector<int> gatewayPositions, AreaType type) : tiles(tiles),
    gatewayPositions(gatewayPositions), type(type) {
}


bool Area::isCompatible(const Area&otherArea) {
    // todo 
}
