//
// Created by Enzo Renard on 19/11/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Game.hpp"

Game::Game() : activeLevel(-1) {
    next_level();
}

void Game::add_level(const Level&level) {
    levels.push_back(level);
}

void Game::next_level() {
    auto level = Level(++activeLevel);
    levels.push_back(level.generate());
}

Level Game::getActiveLevel() {
    for (auto level: levels) {
        if (level.getId() == this->activeLevel) {
            return level;
        }
    }
    auto level = Level(-1).generate();
    add_level(level);
    return level;
}

int Game::get_area_guid_current_level(int x, int y) const {
    return levels.at(activeLevel).get_area_guid(x, y);
}

int Game::getPlayerMaxHealth() const {
    return player.getMaxHealth();
}

int Game::getPlayerCurrentHealth() const {
    return player.getHealth();
}

void Game::addPlayerMaxHealth(int health) {
    player.increaseMaxHealth(health);
}

void Game::addPlayerHealth(int health) {
    player.increaseHealth(health);
}

void Game::takePlayerDamage(int damage) {
    player.increaseHealth(-damage);
}

bool Game::if_can_spawn_current_level_spawn_at(int areaX, int areaY, int spawdId) {
    if (levels.at(activeLevel).can_spawn_at(areaX, areaY, spawdId)) {
        levels.at(activeLevel).spawn_at(areaX, areaY, spawdId);
        return true; // spawn
    }
    return false; // can't spawn
}
