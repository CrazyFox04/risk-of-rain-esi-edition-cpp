//
// Created by Enzo Renard on 19/11/2024.
//
#include "Game.hpp"

Game::Game() : activeLevel(-1), levels(){
}

void Game::add_level(const Level& level) {
    levels.push_back(level);
}

void Game::next_level() {
    levels.push_back(Level(++activeLevel).generate());
}

Level Game::getActiveLevel() {
    return std::ranges::find_first_of(levels, [](const Level& level1, const ));
}
