//
// Created by Enzo Renard on 19/11/2024.
//
#include <random>
//#include "Area.hpp"
#include "Direction.hpp"
#include <Areas.hpp>
#include <utility>

Area Area::getRandomArea() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, DefinedAreas::size());
    return DefinedAreas::get(static_cast<Areas>(dis(gen))).area;
}

Area::Area() : id(FILLED_ID) {
}

Area::Area(int id, std::set<Direction2D> gatewayPositions) : id(id), gatewayPositions(std::move(gatewayPositions)) {
}


bool Area::isCompatible(Direction2D direction, const Area&otherArea) {
    return otherArea.gatewayPositions.contains(Direction::getOppositeDirection(direction));
}

int Area::getId() const {
    return id;
}