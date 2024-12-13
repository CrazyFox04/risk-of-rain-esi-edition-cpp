//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef AREA_HPP
#define AREA_HPP
#include <Tile.hpp>
#include "Direction.hpp"
#include <set>
#include "AreaType.hpp"

class Area {
    static constexpr int FILLED_ID = 0;
    int id;
    std::set<Direction2D> gatewayPositions;

public:
    Area();

    Area(int id, std::set<Direction2D> gatewayPositions);

    static Area getRandomArea();

    bool isCompatible(Direction2D sourceDirection, const Area&otherArea);

    int getId() const;
};
#endif //AREA_HPP
