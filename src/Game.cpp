//
// Created by Enzo Renard on 19/11/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Game.hpp"

Game::Game() : activeLevel(-1) {
}

void Game::add_level(const Level&level) {
    levels.push_back(level);
}

void Game::next_level() {
    levels.push_back(Level(++activeLevel).generate());
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
