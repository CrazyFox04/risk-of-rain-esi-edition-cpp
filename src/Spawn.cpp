//
// Created by Enzo Renard on 25/12/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Spawn.hpp"
#include <random>
#include <chrono>
#include <stdexcept>

Spawn::Spawn(int id, int min_spawn_cool_down, int max_spawn_cool_down): Spawn(
    id, min_spawn_cool_down, max_spawn_cool_down, false) {
}

Spawn::Spawn(int id, int min_spawn_cool_down, int max_spawn_cool_down, bool canSpawBoss) : id(id), boss(canSpawBoss) {
    // randomise the spawn cool down
    if (min_spawn_cool_down > max_spawn_cool_down) {
        throw std::invalid_argument("min_spawn_cool_down must be less than or equal to max_spawn_cool_down");
    }
    if (min_spawn_cool_down < 0 || max_spawn_cool_down < 0) {
        throw std::invalid_argument("min_spawn_cool_down and max_spawn_cool_down must be positive");
    }
    this->spawnCoolDown = get_random_spawn_cool_down(min_spawn_cool_down, max_spawn_cool_down);
}

double Spawn::get_random_spawn_cool_down(int min_spawn_cool_down, int max_spawn_cool_down) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min_spawn_cool_down, max_spawn_cool_down);
    return dis(gen);
}

int Spawn::getId() const {
    return this->id;
}

std::chrono::time_point<std::chrono::steady_clock> Spawn::getLastTimeSpawned() const {
    return this->lastTimeSpawned;
}

bool Spawn::canSpawn() const {
    if (lastTimeSpawned.time_since_epoch().count() == 0) {
        return true;
    }
    return std::chrono::steady_clock::now() - lastTimeSpawned >= std::chrono::duration<double>(spawnCoolDown);
}

void Spawn::spawn() {
    if (!canSpawn()) {
        throw std::runtime_error("Cannot spawn, cool down not reached");
    }
    this->lastTimeSpawned = std::chrono::steady_clock::now();
}

bool Spawn::canSpawnBoss() const {
    return boss;
}

void Spawn::spawnBoss() {
    if (!canSpawnBoss()) {
        throw std::runtime_error("Cannot spawn boss");
    }
    spawn();
    boss = false;
}
