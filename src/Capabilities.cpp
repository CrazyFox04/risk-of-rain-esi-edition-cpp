//
// Created by Enzo Renard on 26/12/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Capabilities.hpp"

Capabilities::Capabilities(std::vector<Attack> attacks, std::set<std::shared_ptr<Movement>> movements,
                           bool hasJetPack): jetPack(0, 0, 0, 0) {
    for (const auto&attack: attacks) {
        this->attacks.emplace_back(attack);
    }
    for (const auto&movement: movements) {
        this->movements.emplace(movement->getName(), movement);
    }
    if (hasJetPack) {
        jetPack = JetPack(JetPack::DEF_FORCE, JetPack::DEF_TIME, JetPack::DEF_COOLDOWN,
                          JetPack::DEF_LANDING_ANIMATION_TIME);
    }
}

std::chrono::time_point<std::chrono::steady_clock> Capabilities::getLastAttackTime() const {
    std::chrono::time_point<std::chrono::steady_clock> lastAttackTime = std::chrono::steady_clock::now();
    for (Attack attack : attacks) {
        if (attack.getLastUsageTime() > lastAttackTime) {
            lastAttackTime = attack.getLastUsageTime();
        }
    }
    return lastAttackTime;
}

bool Capabilities::hasThisAttack(std::string name) const {
    for (const auto & attack : attacks) {
        if (attack.getName() == name) {
            return true;
        }
    }
    return false;
}

bool Capabilities::hasThisMovement(std::string name) const {
    return movements.contains(name);
}

bool Capabilities::canUse(std::string name) const {
    if (name == "JETPACK") {
        return jetPack.canActivate();
    }
    if (hasThisAttack(name)) {
        return getCopyAttack(name).canUse();
    }
    if (hasThisMovement(name)) {
        return movements.at(name)->canUse();
    }
    return false; // doesn't have this capability
}

Attack Capabilities::getCopyAttack(std::string& name) const {
    if (!hasThisAttack(name)) {
        throw std::invalid_argument("This attack does not exist");
    }
    for (const auto attack : attacks) {
        if (attack.getName() == name) {
            return attack;
        }
    }
}

std::shared_ptr<Movement> Capabilities::getMovement(std::string name) const {
    if (!hasThisMovement(name)) {
        throw std::invalid_argument("This movement does not exist");
    }
    return movements.at(name);
}

JetPack Capabilities::getJetPack() const {
    return jetPack;
}

int Capabilities::use(std::string name) {
    if (!canUse(name)) {
        throw std::invalid_argument("This capability cannot be used");
    }
    if (name == "JETPACK") {
        jetPack.activate();
        return 0;
    }
    if (hasThisAttack(name)) {
        getAttack(name).use();
        return getAttack(name).getDamage();
    }
    if (hasThisMovement(name)) {
        movements.at(name)->use();
        return 0;
    }
}

bool Capabilities::isBusy() const {
    for (Attack attack : attacks) {
        if (attack.isUsing()) {
            return true;
        }
    }
    for (const auto&[name, movement]: movements) {
        if (movement->isUsing()) {
            return true;
        }
    }
    return jetPack.isUsing();
}

int Capabilities::isMoving() const {
    if (movements.at("RUN")->isUsing()) {
        return DefinedMovements::getMovementIndex("RUN");
    }
    if (movements.at("JUMP")->isUsing()) {
        return DefinedMovements::getMovementIndex("JUMP");
    }
    if (movements.at("DASH")->isUsing()) {
        return DefinedMovements::getMovementIndex("DASH");
    }
    if (movements.at("CLIMB")->isUsing()) {
        return DefinedMovements::getMovementIndex("CLIMB");
    }
    if (jetPack.isUsing()) {
        return DefinedMovements::getMovementIndex("JETPACK");
    }
    return -1;
}

void Capabilities::increaseAttackDamage(double amount, std::string&attacksName) {
    if (hasThisAttack(attacksName)) {
        getAttack(attacksName).increaseDamage(amount);
    }
}

void Capabilities::increaseMovementForce(const std::string&string, double amount) {
    if (hasThisMovement(string)) {
        movements.at(string)->increaseForce(amount);
    }
}

std::vector<std::string> Capabilities::getCharacterAttacksName() {
    std::vector<std::string> attacksName;
    for (Attack attack : attacks) {
        attacksName.emplace_back(attack.getName());
    }
    return attacksName;
}

void Capabilities::stop(std::string name) {
    if (name == "JETPACK") {
        jetPack.stop();
        return;
    }
    if (hasThisMovement(name)) {
        movements.at(name)->stop();
    }
}

Attack Capabilities::getAttackAt(int attack_index) const {
    return attacks.at(attack_index);
}

Attack& Capabilities::getAttack(std::string& name) {
    for (Attack& attack : attacks) {
        if (attack.getName() == name) {
            return attack;
        }
    }
    throw std::invalid_argument("This attack does not exist");
}