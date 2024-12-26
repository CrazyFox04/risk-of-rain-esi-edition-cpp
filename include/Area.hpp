//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef AREA_HPP
#define AREA_HPP
#include "Enemies.hpp" // todo
#include "Direction.hpp"
#include "Spawn.hpp"
#include <set>

class Area {
    static constexpr int FILLED_ID = 0;
    int type;
    int id;
    std::set<Direction2D> gatewayPositions;
    std::vector<Spawn> spawns;

    Spawn& get_spawn(int spawn_id);

public:
    Area();

    Area(int type, int max_id, std::set<Direction2D> gatewayPositions);

    Area(int type, int max_id, std::set<Direction2D> gatewayPositions, std::vector<Spawn> spawns);

    static Area getRandomArea();

    bool isCompatible(Direction2D sourceDirection, const Area&otherArea);

    int get_type() const;

    int get_id() const;

    int get_guid() const;

    std::set<Direction2D> get_gateway_positions() const;

    static int get_random_area_id(int max_id) ;

    bool can_spawn(int spawd_id);

    void spawn(int spawd_id);
};
#endif //AREA_HPP
