//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef GAME_HPP
#define GAME_HPP
#include "Player.hpp"

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

    int get_area_guid_current_level(int x, int y) const;

    int getPlayerMaxHealth() const;

    int getPlayerCurrentHealth() const;

    void addPlayerMaxHealth(int health);

    void addPlayerHealth(int health);

    void takePlayerDamage(int damage);

    bool if_can_spawn_current_level_spawn_at(int areaX, int areaY, int spawdId);
};
#endif //GAME_HPP
