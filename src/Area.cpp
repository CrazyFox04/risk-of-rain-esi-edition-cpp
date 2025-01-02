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

Area::Area(const int type, const int max_id, std::set<Direction2D> gatewayPositions) : type(type),
                                                                           gatewayPositions(
                                                                               std::move(gatewayPositions)) {
    if (max_id < 1 || max_id > 99) {
        throw std::invalid_argument("max_id must be less than 100");
    }
    id = get_random_area_id(max_id);
}

Area::Area(const int type, const int max_id, std::set<Direction2D> gatawayPositions, std::vector<Spawn> spawns) : Area(type, max_id,
    std::move(
        gatawayPositions)) {
    this->spawns = std::move(spawns);
}

Area::Area(const int type, const int max_id, std::set<Direction2D> gatewayPositions, std::vector<Spawn> spawns, std::vector<Chest> chests) : Area(
    type, max_id, std::move(gatewayPositions), std::move(spawns)) {
    this->chests = std::move(chests);
}


bool Area::isCompatible(const Direction2D&sourceDirection, const Area&otherArea) const {
    if (otherArea.type == -1) {
        return true;
    }
    if (otherArea.type == 0 && !gatewayPositions.contains(sourceDirection)) {
        return true;
    }
    return gatewayPositions.contains(sourceDirection) && otherArea.gatewayPositions.contains(
               Direction::getOppositeDirection(sourceDirection));
}

int Area::get_type() const {
    return type;
}

int Area::get_random_area_id(const int max_id) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, max_id);
    return dis(gen);
}

int Area::get_id() const {
    return id;
}

int Area::get_guid() const {
    return type * 10 + id;
}

std::set<Direction2D> Area::get_gateway_positions() const {
    return gatewayPositions;
}

Spawn& Area::get_spawn(int spawn_id) {
    auto it = std::ranges::find_if(spawns, [spawn_id](const Spawn& spawn) {
         return spawn.getId() == spawn_id;
     });
    if (it != spawns.end()) {
        return *it; 
    }
    throw std::invalid_argument("No spawn with id " + std::to_string(spawn_id));
}

bool Area::can_spawn(int spawd_id) {
    return get_spawn(spawd_id).canSpawn();
}

void Area::spawn(int spawd_id) {
    get_spawn(spawd_id).spawn();
}

std::vector<int> Area::get_spawn_ids() const {
    std::vector<int> ids;
    ids.reserve(spawns.size()); 
    std::ranges::transform(spawns, std::back_inserter(ids), [](const Spawn& spawn) {
        return spawn.getId();
    });
    return ids;
}

bool Area::canSpawnBoss() const {
    return std::ranges::any_of(spawns, [](const Spawn& spawn) {
        return spawn.canSpawnBoss();
    });
}

void Area::spawnBoss(const int spawn_id) {
    get_spawn(spawn_id).spawnBoss();
}

Item Area::openChest(const int chest_id) {
    const auto it = std::ranges::find_if(chests, [chest_id](const Chest& chest) {
            return chest.getId() == chest_id;
        });
    if (it != chests.end()) {
        return it->open();
    }
    throw std::invalid_argument("No chest with id " + std::to_string(chest_id));
}

bool Area::isChestEmpty(const int chest_id) const {
    const auto it = std::ranges::find_if(chests, [chest_id](const Chest& chest) {
        return chest.getId() == chest_id;
    });
    return it == chests.end() ? true : it->isEmpty();
}
