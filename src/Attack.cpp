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

void Attack::use() {
    if (!canUse()) {
        throw std::runtime_error("Cannot use attack");
    }
    lastUsageTime = std::chrono::steady_clock::now();
}

bool Attack::isUsing() const {
    return std::chrono::steady_clock::now() - lastUsageTime < std::chrono::duration<double>(animationTime) +
           std::chrono::duration<double>(chargeTime) + std::chrono::duration<double>(cooldown);
}

bool Attack::canUse() const {
    return !isUsing();
}

int Attack::getDamage() const {
    return damage;
}

std::chrono::time_point<std::chrono::steady_clock> Attack::getLastUsageTime() const {
    return lastUsageTime;
}