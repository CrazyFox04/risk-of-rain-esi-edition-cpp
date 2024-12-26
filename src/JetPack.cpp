//
// Created by Enzo Renard on 26/12/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "JetPack.hpp"

JetPack::JetPack(double force, double maxFuel, double cooldown, double landingAnimationTime) : force(force), maxFuel(maxFuel), cooldown(cooldown), landingAnimationTime(landingAnimationTime) {
}

void JetPack::use() {
    if (canUse()) {
        lastJetpackUse = std::chrono::steady_clock::now();
    }
}

double JetPack::getFuel() const {
    std::chrono::duration<double> timeSinceLastUse = std::chrono::steady_clock::now() - lastJetpackUse;
    return std::max(0.0, maxFuel - timeSinceLastUse.count() * force);
}

bool JetPack::canUse() const {
    
}

bool JetPack::isUsing() const {
    return 
}