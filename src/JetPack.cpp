//
// Created by Enzo Renard on 26/12/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "JetPack.hpp"

JetPack::JetPack(double force, double maxTime, double cooldown, double landingAnimationTime) : force(force),
    maxTime(maxTime), cooldown(cooldown), landingAnimationTime(landingAnimationTime) {
}

void JetPack::activate() {
    if (!canActivate()) {
        throw std::runtime_error("Cannot use jetpack");
    }
    lastJetpackUse = std::chrono::steady_clock::now();
}

bool JetPack::canActivate() const {
    return std::chrono::steady_clock::now() - lastJetpackUse < std::chrono::duration<double>(maxTime) +
           std::chrono::duration<double>(cooldown) + std::chrono::duration<double>(landingAnimationTime);
}

bool JetPack::isUsing() const {
    return std::chrono::steady_clock::now() - lastJetpackUse < std::chrono::duration<double>(maxTime);
}

double JetPack::getForce() const {
    return force;
}

double JetPack::getLandAnimationTime() const {
    return landingAnimationTime;
}

double JetPack::getMaxTime() const {
    return maxTime;
}