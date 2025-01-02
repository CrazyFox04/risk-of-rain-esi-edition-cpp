//
// Created by Enzo Renard on 19/11/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Enemies.hpp"
#include "Enemy.hpp"

Enemy::Enemy(const std::string&type, const int maxHealth, const double followRange, const double attackRange, const double hurtTime,
             const Capabilities&capabilities,
             const bool isBoss) : Character(type,maxHealth, hurtTime, capabilities), isBoss(isBoss),
                            followRange(followRange), attackRange(attackRange) {
}

void Enemy::addItem(const Item&item) {
    throw std::invalid_argument("Cannot add items to an enemy");
}

double Enemy::getFollowRange() const {
    return followRange;
}

double Enemy::getAttackRange() const {
    return attackRange;
}

bool Enemy::getIsBoss() const {
    return isBoss;
}

void Enemy::die() {
    // nop
}