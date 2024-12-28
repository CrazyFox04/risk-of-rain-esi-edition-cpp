//
// Created by Enzo Renard on 26/12/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Attack.hpp"

Attack::Attack(const std::string&name, int damage, double cooldown, double chargeTime,
               double animationTime) : name(name), damage(damage), cooldown(cooldown), chargeTime(chargeTime),
                                       animationTime(animationTime) {
}

int Attack::use() {
    if (!canUse()) {
        throw std::runtime_error("Cannot use attack");
    }
    lastUsageTime = std::chrono::steady_clock::now();
    return damage;
}

bool Attack::isUsing() const {
    if (lastUsageTime.time_since_epoch().count() == 0) {
        return false;
    } 
    return std::chrono::steady_clock::now() - lastUsageTime < std::chrono::duration<double>(animationTime) +
           std::chrono::duration<double>(chargeTime);
}

bool Attack::canUse() const {
    if (lastUsageTime.time_since_epoch().count() == 0) {
        return true;
    }
    return std::chrono::steady_clock::now() - lastUsageTime > std::chrono::duration<double>(animationTime) +
           std::chrono::duration<double>(chargeTime) + std::chrono::duration<double>(cooldown);
}

int Attack::getDamage() const {
    return damage;
}

std::string Attack::getName() const {
    return name;
}

double Attack::getCooldown() const {
    return cooldown;
}

double Attack::getChargeTime() const {
    return chargeTime;
}

double Attack::getAnimationTime() const {
    return animationTime;
}

std::chrono::time_point<std::chrono::steady_clock> Attack::getLastUsageTime() const {
    return lastUsageTime;
}
