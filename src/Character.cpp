//
// Created by Enzo Renard on 19/11/2024.
//
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

void Character::addItem(std::shared_ptr <Item> item) {
        items.push_back(item);
}