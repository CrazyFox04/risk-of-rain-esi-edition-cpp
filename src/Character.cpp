//
// Created by Enzo Renard on 19/11/2024.
//
#include "Character.hpp";

Character::Character(int health, int speed, int damage): health(health), speed(speed), damage(damage) {
}

void Character::hit(int damage) {
    health -= damage;
}

void Character::kill() {
    health = 0;
}

void Character::canHit(int damage) {
    //items.for todo
}


