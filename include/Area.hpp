//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef AREA_HPP
#define AREA_HPP
#include "Direction.hpp"
#include <set>

class Area {
    static constexpr int FILLED_ID = 0;
    int type;
    int id;
    std::set<Direction2D> gatewayPositions;

public:
    Area();

    Area(int type, int max_id, std::set<Direction2D> gatewayPositions);

    static Area getRandomArea();

    bool isCompatible(Direction2D sourceDirection, const Area&otherArea);

    int get_type() const;

    int get_id() const;

    int get_guid() const;

    std::set<Direction2D> get_gateway_positions() const;

    static int get_random_area_id(int max_id) ;
};
#endif //AREA_HPP
