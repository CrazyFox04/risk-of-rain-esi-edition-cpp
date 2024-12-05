//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef GAME_HPP
#define GAME_HPP
#include <Player.hpp>

#include "Level.hpp"

#include <vector>

class Game {
    int activeLevel;
    std::vector<Level> levels;
    Player player;

    void add_level(const Level&level);

    void next_level();

public:
    Game();

    Level getActiveLevel();

    int getPlayerMaxHealth() const;

    int getPlayerCurrentHealth() const;

    void addPlayerMaxHealth(int health);

    void addPlayerHealth(int health);

    void takePlayerDamage(int damage);
};
#endif //GAME_HPP
