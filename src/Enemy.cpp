//
// Created by Enzo Renard on 19/11/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Enemies.hpp"
#include "Enemy.hpp"

Enemy::Enemy(std::string type, int maxHealth, double followRange, double attackRange, double hurtTime,
             Capabilities capabilities,
             bool isBoss) : Character(type,maxHealth, hurtTime, capabilities), isBoss(isBoss),
                            followRange(followRange), attackRange(attackRange) {
}

void Enemy::addItem(std::shared_ptr<Buff> buff) {
    throw std::invalid_argument("Cannot add items to an enemy");
}

double Enemy::getFollowRange() const {
    return followRange;
}

double Enemy::getAttackRange() const {
    return attackRange;
}
