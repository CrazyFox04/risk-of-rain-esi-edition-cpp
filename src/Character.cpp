//
// Created by Enzo Renard on 19/11/2024.
//
#include "Character.hpp"

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
    // Implémentez ici la logique de mort du personnage
}

bool Character::canHit(int damage) const {
    return health > 0 && damage > 0;
}

void Character::addItem(std::shared_ptr <Item> item) {
        items.push_back(item);
}

void Character::modifyStats(int healthMod, int speedMod, int damageMod) {
    health += healthMod;
    speed += speedMod;
    damage += damageMod;
}

