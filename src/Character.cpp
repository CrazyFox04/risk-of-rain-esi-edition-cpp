//
// Created by Enzo Renard on 19/11/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Character.hpp"
#include "Weapon.h"
#include "Buff.h"

Character::Character(int health, int speed, int damage)
        : health(health), speed(speed), damage(damage) {}

void Character::hit(int damage) {
    if (canHit(damage)) {
        health -= damage;
        if (health <= 0) {
            kill();
        }
    }
}

void Character::kill() {
    health = 0;
    // todo
}

bool Character::canHit(int damage) const {
    return health > 0 && damage > 0;
}

void Character::addItem(std::shared_ptr <Buff> item) {
        buffs.push_back(item);
}