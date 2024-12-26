//
// Created by Enzo Renard on 26/12/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Capabilities.hpp"

Capabilities::Capabilities(std::set<Attack> attacks, std::set<std::shared_ptr<Movement>> movements,
                           bool hasJetPack): jetPack(0, 0, 0, 0) {
    for (const auto&attack: attacks) {
        this->attacks.emplace(attack.getName(), attack);
    }
    for (const auto&movement: movements) {
        this->movements.emplace(movement->getName(), *movement);
    }
    if (hasJetPack) {
        jetPack = JetPack(JetPack::DEF_FORCE, JetPack::DEF_TIME, JetPack::DEF_COOLDOWN,
                          JetPack::DEF_LANDING_ANIMATION_TIME);
    }
}

std::chrono::time_point<std::chrono::steady_clock> Capabilities::getLastAttackTime() const {
    std::chrono::time_point<std::chrono::steady_clock> lastAttackTime = std::chrono::steady_clock::now();
    for (const auto&[name, attack]: attacks) {
        if (attack.getLastUsageTime() > lastAttackTime) {
            lastAttackTime = attack.getLastUsageTime();
        }
    }
    return lastAttackTime;
}

bool Capabilities::hasThisAttack(std::string&name) const {
    return attacks.contains(name);
}

bool Capabilities::hasThisMovement(std::string&name) const {
    return movements.contains(name);
}

bool Capabilities::canUse(std::string name) const {
    if (name == "JETPACK") {
        return jetPack.canUse();
    }
    if (hasThisAttack(name)) {
        return attacks.at(name).canUse();
    }
    if (hasThisMovement(name)) {
        return movements.at(name).canUse();
    }
    throw std::invalid_argument("This capability does not exist");
}

Attack Capabilities::getAttack(std::string name) const {
    if (!hasThisAttack(name)) {
        throw std::invalid_argument("This attack does not exist");
    }
    return attacks.at(name);
}

Movement Capabilities::getMovement(std::string name) const {
    if (!hasThisMovement(name)) {
        throw std::invalid_argument("This movement does not exist");
    }
    return movements.at(name);
}