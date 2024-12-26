//
// Created by Enzo Renard on 19/11/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Enemy.hpp"

Enemy::Enemy(int maxHealth, double followRange, double attackRange, double hurtTime,
             Capabilities capabilities,
             bool isBoss) : Character(maxHealth, hurtTime, capabilities), isBoss(isBoss),
                            followRange(followRange), attackRange(attackRange) {
}

void Enemy::addItem(std::shared_ptr<Buff> buff) {
    throw std::invalid_argument("Cannot add items to an enemy");
}
