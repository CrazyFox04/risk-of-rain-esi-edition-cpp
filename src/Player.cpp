//
// Created by Enzo Renard on 19/11/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Player.hpp"
#include <algorithm>

Player::Player(int health, int speed, int damage)
    : Character(health, speed, damage), activeWeapon(nullptr) {
}

Player::Player() : Player(DEF_HEALTH, DEF_SPEED, DEF_DAMAGE) {
}


bool Player::canShoot() const {
    return activeWeapon != nullptr;
}

void Player::useItem(const std::shared_ptr<Buff>&item) {
    if (!item) return;

    Buff buff = *item;
    switch (buff) {
        case Buff::HEALTH_POTION:
            increaseHealth(BuffValue::getValue(buff));
            break;
        case Buff::SPEED_BOOST:
            increaseSpeed(BuffValue::getValue(buff));
            break;
        case Buff::DAMAGE_BOOST:
            increaseDamage(BuffValue::getValue(buff));
            break;
        default:
            break;
    }

    buffs.push_back(item);
}

void Player::switchWeapons() {
    if (weapons.size() < 2) return;

    auto it = std::find(weapons.begin(), weapons.end(), activeWeapon);
    if (it != weapons.end()) {
        size_t currentIndex = std::distance(weapons.begin(), it);
        size_t nextIndex = (currentIndex + 1) % weapons.size();
        activeWeapon = weapons[nextIndex];
    }
    else if (!weapons.empty()) {
        activeWeapon = weapons[0];
    }
}

void Player::addItem(const std::shared_ptr<Buff>&item) {
    Character::addItem(item);
}

std::shared_ptr<Weapon> Player::getActiveWeapon() const {
    return activeWeapon;
}

std::shared_ptr<Buff> Player::getItem(size_t index) const {
    if (index < buffs.size()) {
        return buffs[index];
    }
    return nullptr;
}

void Player::increaseHealth(int amount) {
    health += amount;
}

void Player::increaseMaxHealth(int amount) {
    maxHealth += amount;
}

void Player::increaseSpeed(int amount) {
    speed += amount;
}

void Player::increaseDamage(int amount) {
    damage += amount;
}

void Player::attack() {
    //todo
}

void Player::shoot() {
    if (!canShoot()) {
        return;
    }
    else {
        // todo
    }
}
