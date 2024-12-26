//
// Created by Enzo Renard on 25/12/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Spawn.hpp"
#include <ctime>
#include <random>
#include <stdexcept>

Spawn::Spawn(int id, int min_spawn_cool_down, int max_spawn_cool_down) : id(id), lastTimeSpawned(-1) {
    // randomise the spawn cool down
    if (min_spawn_cool_down > max_spawn_cool_down) {
        throw std::invalid_argument("min_spawn_cool_down must be less than or equal to max_spawn_cool_down");
    }
    if (min_spawn_cool_down < 0 || max_spawn_cool_down < 0) {
        throw std::invalid_argument("min_spawn_cool_down and max_spawn_cool_down must be positive");
    }
    spawn_cool_down = get_random_spawn_cool_down(min_spawn_cool_down, max_spawn_cool_down);
}

int Spawn::get_random_spawn_cool_down(int min_spawn_cool_down, int max_spawn_cool_down) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min_spawn_cool_down, max_spawn_cool_down);
    return dis(gen);
}

int Spawn::getId() const {
    return this->id;
}

int Spawn::getLastTimeSpawned() const {
    return this->lastTimeSpawned;
}

bool Spawn::canSpawn() const {
   return this->lastTimeSpawned == -1 || this->lastTimeSpawned + this->spawn_cool_down < std::time(nullptr);
}

void Spawn::spawn() {
    if (!canSpawn()) {
        throw std::runtime_error("Cannot spawn, cool down not reached");
    }
    this->lastTimeSpawned = std::time(nullptr);
}