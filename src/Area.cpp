//
// Created by Enzo Renard on 19/11/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include <random>
#include "Direction.hpp"
#include <utility>
#include "Area.hpp"
#include "Areas.hpp"

Area Area::getRandomArea() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, DefinedAreas::size());
    return DefinedAreas::get(static_cast<Areas>(dis(gen))).area;
}

Area::Area() : Area(-1, 1, {}, {}) {
}

Area::Area(int type, int max_id, std::set<Direction2D> gatewayPositions) : type(type),
                                                                           gatewayPositions(
                                                                               std::move(gatewayPositions)) {
    if (max_id < 1 || max_id > 99) {
        throw std::invalid_argument("max_id must be less than 100");
    }
    id = get_random_area_id(max_id);
}

Area::Area(int type, int max_is, std::set<Direction2D> gatawayPositions, std::vector<Spawn> spawns) : Area(type, max_is,
    std::move(
        gatawayPositions)){
    this->spawns = spawns;
}

bool Area::isCompatible(Direction2D direction, const Area&otherArea) {
    if (otherArea.type == -1) {
        return true;
    }
    if (otherArea.type == 0 && !gatewayPositions.contains(direction)) {
        return true;
    }
    return gatewayPositions.contains(direction) && otherArea.gatewayPositions.contains(
               Direction::getOppositeDirection(direction));
}

int Area::get_type() const {
    return type;
}

int Area::get_random_area_id(int max_id) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, max_id);
    return dis(gen);
}

int Area::get_id() const {
    return id;
}

int Area::get_guid() const {
    return type * 100 + id;
}

std::set<Direction2D> Area::get_gateway_positions() const {
    return gatewayPositions;
}

Spawn& Area::get_spawn(int spawn_id) {
    for (Spawn& spawn: spawns) {
        if (spawn.getId() == spawn_id) {
            return spawn; // return spawn (not copy)
        }
    }
    throw std::invalid_argument("No spawn with id " + std::to_string(spawn_id));
}

bool Area::can_spawn(int spawd_id) {
    return get_spawn(spawd_id).canSpawn();
}

void Area::spawn(int spawd_id) {
    get_spawn(spawd_id).spawn();
}