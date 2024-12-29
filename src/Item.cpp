//
// Created by Julien Delcombel on 29/12/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Item.hpp"

Item::Item(const std::string&name, double effect, double effectDuration) : name(name), effect(effect),
                                                                            effectDuration(effectDuration) {
}

double Item::use() {
    if (!canUse()) {
        throw std::runtime_error("Cannot use item");
    }
    lastUsageTime = std::chrono::steady_clock::now();
    return effect;
}

bool Item::isUsing() const {
    if (lastUsageTime.time_since_epoch().count() == 0) {
        return false;
    }
    return std::chrono::steady_clock::now() - lastUsageTime < std::chrono::duration<double>(effectDuration);
}

// On ne pourrait pas utiliser plusieurs items en même temps?
bool Item::canUse() const {
    if (lastUsageTime.time_since_epoch().count() == 0) {
        return true;
    }
    return std::chrono::steady_clock::now() - lastUsageTime > std::chrono::duration<double>(effectDuration);
}

double Item::getEffect() const {
    return effect;
}

std::string Item::getName() const {
    return name;
}

double Item::getEffectDuration() const {
    return effectDuration;
}

std::chrono::time_point<std::chrono::steady_clock> Item::getLastUsageTime() const {
    return lastUsageTime;
}