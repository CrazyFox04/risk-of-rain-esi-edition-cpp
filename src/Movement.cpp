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
    return std::chrono::steady_clock::now() - lastUsageTime < std::chrono::duration<double>(animationTime);
}

bool Movement::canUse() const {
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