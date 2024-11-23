//
// Created by Enzo Renard on 19/11/2024.
//
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
