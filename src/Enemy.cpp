//
// Created by Enzo Renard on 19/11/2024.
//
#include "Enemy.hpp"

Enemy::Enemy(int health, int speed, int damage, bool canThrow)
        : Character(health, speed, damage), canThrow(canThrow) {}

void Enemy::attack() {
    // Implémentez la logique d'attaque spécifique à l'ennemi
}

void Enemy::shoot() {
    if (canThrow) {
        // Implémentez la logique de tir spécifique à l'ennemi
    }
}