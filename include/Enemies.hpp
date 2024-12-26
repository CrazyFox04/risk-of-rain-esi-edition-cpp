//
// Created by Enzo Renard on 26/12/2024.
//

#ifndef ENEMIES_HPP
#define ENEMIES_HPP
#include <unordered_set>
#include "Enemy.hpp"

enum Enemies {
    SPECTRUM,
    SMALL_MONSTER,
    SHIELD_DROID
};

struct DefinedEnemies {
    Enemy enemy;
    static DefinedEnemies get(const Enemies enemies);
    static int size();
    static std::unordered_set<Enemies> getAllEnemies();
};
#endif //ENEMIES_HPP
