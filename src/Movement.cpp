//
// Created by Enzo Renard on 26/12/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Movement.hpp"

Movement::Movement(std::string name, double force, double animationTime, double cooldown) : name(std::move(name)),
    force(force), animationTime(animationTime), cooldown(cooldown) {
}

bool Movement::isUsing() const {
    if (lastUsageTime.time_since_epoch().count() == 0) {
        return false;
    }
    return std::chrono::steady_clock::now() - lastUsageTime < std::chrono::duration<double>(animationTime);
}

bool Movement::canUse() const {
    if (lastUsageTime.time_since_epoch().count() == 0) {
        return true;
    }
    return std::chrono::steady_clock::now() - lastUsageTime > std::chrono::duration<double>(cooldown) +
           std::chrono::duration<double>(animationTime);
}

void Movement::use() {
    if (!canUse()) {
        throw std::invalid_argument("This movement is unavailable");
    }
    lastUsageTime = std::chrono::steady_clock::now();
}

std::string Movement::getName() const {
    return name;
}

std::chrono::time_point<std::chrono::steady_clock> Movement::getLastUsageTime() const {
    return lastUsageTime;
}

double Movement::getForce() const {
    return force;
}

double Movement::getAnimationTime() const {
    return animationTime;
}

double Movement::getCooldown() const {
    return cooldown;
}

void Movement::stop() {
    // nop
}