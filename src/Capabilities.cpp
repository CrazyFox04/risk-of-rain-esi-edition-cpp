//
// Created by Enzo Renard on 26/12/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Capabilities.hpp"

Capabilities::Capabilities(std::vector<Attack> attacks, std::set<std::shared_ptr<Movement>> movements, bool hasJetPack)
    : attacks(std::move(attacks)),
      movements(),
      jetPack(hasJetPack
                  ? JetPack(JetPack::DEF_FORCE, JetPack::DEF_TIME, JetPack::DEF_COOLDOWN,
                            JetPack::DEF_LANDING_ANIMATION_TIME)
                  : JetPack(0, 0, 0, 0)) {
    std::ranges::for_each(movements, [this](const std::shared_ptr<Movement>&movement) {
        this->movements.emplace(movement->getName(), movement);
    });
}

std::chrono::time_point<std::chrono::steady_clock> Capabilities::getLastAttackTime() const {
    std::chrono::time_point<std::chrono::steady_clock> lastAttackTime = std::chrono::steady_clock::now();
    for (const Attack& attack: attacks) {
        if (attack.getLastUsageTime() > lastAttackTime) {
            lastAttackTime = attack.getLastUsageTime();
        }
    }
    return lastAttackTime;
}

bool Capabilities::hasThisAttack(std::string name) const {
    return std::ranges::find_if(attacks, [&name](const Attack&attack) {
        return attack.getName() == name;
    }) != attacks.end();
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

Attack Capabilities::getCopyAttack(std::string&name) const {
    const auto it = std::ranges::find_if(attacks, [&name](const Attack&attack) {
        return attack.getName() == name;
    });
    if (it == attacks.end()) {
        throw std::invalid_argument("This attack does not exist");
    }
    return *it;
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
    return -1;
}

bool Capabilities::isBusy() const {
    return
        std::ranges::any_of(attacks, [](const Attack&attack) {return attack.isUsing();})
    || std::ranges::any_of(movements, [](const auto&pair) {return pair.second->isUsing();})
    || jetPack.isUsing();
}

int Capabilities::isMoving() const {
    static const std::vector<std::string> movementNames = {"RUN", "JUMP", "DASH", "CLIMB"};
    for (const auto& name : movementNames) {
        if (movements.at(name)->isUsing()) {
            return DefinedMovements::getMovementIndex(name);
        }
    }
    if (jetPack.isUsing()) {
        return DefinedMovements::getMovementIndex("JETPACK");
    }
    return -1;
}

void Capabilities::increaseAttackDamage(double amount, std::string&attacksName) {
    const auto it = std::ranges::find_if(attacks, [&attacksName](const Attack& attack) {
        return attack.getName() == attacksName;
    });
    if (it != attacks.end()) {
        it->increaseDamage(amount);
    }
}

void Capabilities::increaseMovementForce(const std::string& movementName, double amount) {
    if (const auto it = movements.find(movementName); it != movements.end()) {
        it->second->increaseForce(amount);
    }
}

std::vector<std::string> Capabilities::getCharacterAttacksName() const {
    std::vector<std::string> attacksName;
    attacksName.reserve(attacks.size());  
    for (const Attack& attack : attacks) { 
        attacksName.push_back(attack.getName()); 
    }
    return attacksName;
}

void Capabilities::stop(std::string name) {
    if (name == "JETPACK") {
        jetPack.stop();
    } else {
        if (const auto it = movements.find(name); it != movements.end()) {
            it->second->stop();
        }
    }
}

const Attack& Capabilities::getAttackAt(int attack_index) const {
    return attacks[attack_index];
}


Attack& Capabilities::getAttack(const std::string& name) {
    const auto it = std::ranges::find_if(attacks, 
                                         [&name](const Attack& attack) { return attack.getName() == name; });
    if (it != attacks.end()) {
        return *it;
    }
    throw std::invalid_argument("This attack does not exist");
}
