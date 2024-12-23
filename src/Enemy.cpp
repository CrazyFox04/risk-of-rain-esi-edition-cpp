//
// Created by Enzo Renard on 19/11/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Enemy.hpp"

Enemy::Enemy(int health, int speed, int damage, bool canThrow)
        : Character(health, speed, damage), canThrow(canThrow) {}

void Enemy::attack() {
    // todo
}

void Enemy::shoot() {
    if (!getCanThrow()) {
        return;
    } else {
        // todo
    }
}