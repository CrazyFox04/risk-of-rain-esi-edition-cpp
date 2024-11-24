//
// Created by Enzo Renard on 19/11/2024.
//
#include "Enemy.hpp"

Enemy::Enemy(int health, int speed, int damage, bool canThrow)
        : Character(health, speed, damage), canThrow(canThrow) {}

void Enemy::attack() {
    // todo
}

void Enemy::shoot() {
    if (getCanThrow()) {
        // todo
    }
}