//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef GAME_HPP
#define GAME_HPP
#include "Level.hpp"

#include <vector>

class Game {
    int activeLevel;
    std::vector<Level> levels;

    void add_level(const Level&level);

    void next_level();

public:
    Game();

    Level getActiveLevel();
};
#endif //GAME_HPP
