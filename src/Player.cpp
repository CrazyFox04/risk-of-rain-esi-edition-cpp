//
// Created by Enzo Renard on 19/11/2024.
//
#include "Player.hpp"

Player::Player(int health, int speed, int damage)
        : Character(health, speed, damage), activeWeapon(nullptr) {}

bool Player::canShoot() const {
    return activeWeapon != nullptr;
}

void Player::useItem(const std::shared_ptr<Item> &item) {
    if (item) {
        item->apply(*this);
    }
}

void Player::switchWeapons() {
    if (weapons.size() < 2) return;

    auto it = std::find(weapons.begin(), weapons.end(), activeWeapon);
    if (it != weapons.end()) {
        size_t currentIndex = std::distance(weapons.begin(), it);
        size_t nextIndex = (currentIndex + 1) % weapons.size();
        activeWeapon = weapons[nextIndex];
    } else if (!weapons.empty()) {
        // Si aucune arme active, prend la première
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
    // Vous pouvez ajouter une limite maximale si nécessaire
    // health = std::min(health, maxHealth);
}

void Player::increaseSpeed(int amount) {
    speed += amount;
    // Si vous voulez un multiplicateur au lieu d'une addition :
    // speed = static_cast<int>(speed * (1.0 + amount / 100.0));
}

void Player::increaseDamage(int amount) {
    damage += amount;
    if (activeWeapon) {
        //activeWeapon->increaseDamage(amount);
    }
}

void Player::attack() {
    //todo
}

void Player::shoot() {
    if (canShoot()) {
        //activeWeapon->shoot();
    }
}