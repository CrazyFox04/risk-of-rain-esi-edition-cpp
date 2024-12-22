//
// Created by Enzo Renard on 19/11/2024.
//
#include "Player.hpp"
#include <algorithm>

Player::Player(int health, int speed, int damage)
    : Character(health, speed, damage),
    activeWeapon(nullptr),
    attack1Cooldown(DEF_ATTACK_COOLDOWN),
    attack2Cooldown(DEF_ATTACK_COOLDOWN),
    attack3Cooldown(DEF_ATTACK_COOLDOWN),
    dashCooldown(DEF_DASH_COOLDOWN),
    jetpackFuel(DEF_JETPACK_FUEL),
    maxJumps(DEF_MAX_JUMPS),
    remainingJumps(DEF_MAX_JUMPS),
    lastAttackTime(std::chrono::system_clock::now()),
    lastShootTime(std::chrono::system_clock::now()) {
}

Player::Player() : Player(DEF_HEALTH, DEF_SPEED, DEF_DAMAGE) {
}

// Getters
float Player::getAttack1Cooldown() const { return attack1Cooldown; }
float Player::getAttack2Cooldown() const { return attack2Cooldown; }
float Player::getAttack3Cooldown() const { return attack3Cooldown; }
float Player::getDashCooldown() const { return dashCooldown; }
float Player::getJetpackFuel() const { return jetpackFuel; }
int Player::getMaxJumps() const { return maxJumps; }
int Player::getRemainingJumps() const { return remainingJumps; }

// Reducing cooldowns
void Player::reduceAttackCooldowns(const std::shared_ptr<Buff> &item) {
    if (!item) return;
    float reduction = BuffValue::getValue(*item);
    attack2Cooldown = std::max(0.1f, attack2Cooldown - reduction);
    attack3Cooldown = std::max(0.1f, attack3Cooldown - reduction);
}

void Player::reduceDashCooldown(const std::shared_ptr<Buff> &item) {
    if (!item) return;
    float reduction = BuffValue::getValue(*item);
    dashCooldown = std::max(0.1f, dashCooldown - reduction);
}

// Jetpack and jump methods
void Player::increaseJetpackFuel(const std::shared_ptr<Buff> &item) {
    if (!item) return;
    jetpackFuel += BuffValue::getValue(*item);
}

void Player::increaseMaxJumps(const std::shared_ptr<Buff> &item) {
    if (!item) return;
    maxJumps += BuffValue::getValue(*item);
    remainingJumps = maxJumps;
}

void Player::resetJumps() {
    remainingJumps = maxJumps;
}

bool Player::canShoot() const {
    auto now = std::chrono::system_clock::now();
    if (!activeWeapon) return false;

    WeaponProperties properties = WeaponProperties::getProperties(*activeWeapon);
    auto elapsed = std::chrono::duration<float>(now - lastShootTime).count();
    return elapsed >= properties.cooldown;
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
    if (!canShoot() || !activeWeapon) return;

    WeaponProperties properties = WeaponProperties::getProperties(*activeWeapon);

    // todo
    //for (auto &enemy : getEnemiesInRange()) {
    //    enemy->hit(properties.damage);
    //}
    lastShootTime = std::chrono::system_clock::now();
}
