//
// Created by Enzo Renard on 19/11/2024.
//
#include "Player.hpp"
#include <algorithm>
#include <thread>

Player::Player(const std::string& playerId)
    : Character(DEF_HEALTH, DEF_SPEED, 0),
      attackDamages{10.0f, 20.0f, 30.0f, 40.0f, 50.0f},
      attackCooldowns{0.42f, 1.5f, 5.0f, 2.0f, 5.0f},
      attackAnimTimes{0.42f, 0.4f, 1.0f, 1.0f, 1.0f},
      moveSpeed(DEF_SPEED),
      jumpForce(DEF_JUMP_FORCE),
      dashForce(DEF_DASH_FORCE),
      jetPackSpeed(DEF_JETPACK_SPEED),
      jetpackFuel(DEF_JETPACK_TIME),
      maxJumps(1),
      isDashing(false),
      isJetPacking(false),
      isBusy(false),
      maxHealth(DEF_HEALTH),
      currentHealth(DEF_HEALTH),
      id(playerId),
      lastDashTime(std::chrono::steady_clock::now()),
      lastAttackTime(std::chrono::steady_clock::now()) {}

void Player::selectAttacks(const std::vector<int> &attackIndices) {
    selectedAttacks.clear();
    for (int index : attackIndices) {
        if (index >= 0 && index < 5) {
            selectedAttacks.push_back(index);
        }
    }
}

bool canAttack(int attackIndex) const {
    if (attackIndex < 0 || attackIndex >= 5) return false;

    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration<float>(now - lastAttackTime).count();
    return elapsed >= attackCooldowns[selectedAttacks[attackIndex]] && !isBusy;
}

void Player::attack(int attackIndex) {
    if (!canAttack(attackIndex)) return;

    int selectedAttack = selectedAttacks[attackIndex];
    setIsBusy(true);
    lastAttackTime = std::chrono::system_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(attackAnimTimes[selectedAttack] * 1000)));
    setIsBusy(false);
}

bool Player::canDash() const {
    auto now = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration<float>(now - lastDashTime).count();
    return elapsed >= dashAnimTime && !isBusy;
}

void Player::dash() {
    if (!canDash()) return;

    setIsDashing(true);
    lastDashTime = std::chrono::system_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(dashAnimTime * 1000)));
    setIsDashing(false);
}

void Player::setIsBusy(bool value) {
    isBusy = value;
}

void Player::setIsDashing(bool value) {
    isDashing = value;
}

// Getters
bool Player::getIsBusy() const { return isBusy; }
bool Player::getIsDashing() const { return isDashing; }
bool Player::getIsJetPacking() const { return isJetPacking; }

float Player::getMoveSpeed() const { return moveSpeed; }
float Player::getJumpForce() const { return jumpForce; }
float Player::getDashForce() const { return dashForce; }
float Player::getJetPackSpeed() const { return jetPackSpeed; }
float Player::getJetpackFlightTime() const { return jetpackFuel; }

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

void Player::addItem(const std::shared_ptr<Buff>&item) {
    Character::addItem(item);
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