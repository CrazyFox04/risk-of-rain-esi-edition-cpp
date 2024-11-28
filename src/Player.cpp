//
// Created by Enzo Renard on 19/11/2024.
//
#include "Player.hpp"

Player::Player(int health, int speed, int damage)
        : Character(health, speed, damage), activeWeapon(nullptr) {}

bool Player::canShoot() const {
    return activeWeapon != nullptr;
}

void Player::useItem(const std::shared_ptr<Buff> &buff) {
    if (!buff) return;

    switch (buff->getType()) {
        case ItemType::HEALTH_POTION:
            modifyHealth(buff->getValue());
            break;
        case ItemType::SPEED_BOOST:
            modifySpeed(buff->getValue());
            break;
        case ItemType::DAMAGE_BOOST:
            modifyDamage(buff->getValue());
            break;
    }
    items.push_back(buff);
}

void Player::switchWeapons() {
    if (weapons.size() < 2) return;

    auto it = std::find(weapons.begin(), weapons.end(), activeWeapon);
    if (it != weapons.end()) {
        size_t currentIndex = std::distance(weapons.begin(), it);
        size_t nextIndex = (currentIndex + 1) % weapons.size();
        activeWeapon = weapons[nextIndex];
    } else if (!weapons.empty()) {
        activeWeapon = weapons[0];
    }
}

void Player::addItem(const std::shared_ptr<Item> &item) {
    Character::addItem(item);
}

std::shared_ptr<Weapon> Player::getActiveWeapon() const {
    return activeWeapon;
}

std::shared_ptr<Item> Player::getItem(size_t index) const {
    if (index < items.size()) {
        return items[index];
    }
    return nullptr;
}

void Player::increaseHealth(int amount) {
    health += amount;
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
    } else {
        // todo
    }
}