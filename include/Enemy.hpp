//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <Character.hpp>

class Enemy final : Character {
public:
    Enemy(int health, int speed, int damage);
};
#endif //ENEMY_HPP
