//
// Created by Enzo Renard on 26/12/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Jump.hpp"

Jump::Jump(const double force, const int maxUsage) : Movement("JUMP", force, 0.0, 0.0), maxUsage(maxUsage), currentUsage(0) {
}

void Jump::use() {
    if (!canUse()) {
        throw std::runtime_error("Cannot use jump");
    }
    currentUsage++;
}

bool Jump::canUse() const {
    return currentUsage < maxUsage;
}

void Jump::reset() {
    currentUsage = 0;
}

void Jump::increaseForce(const double amount) {
    maxUsage += amount;
}