//
// Created by Enzo Renard on 26/12/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Animation.hpp"

Animation::Animation(double duration) : duration(duration) {
}

void Animation::start() {
    if (isPlaying()) {
        throw std::runtime_error("Cannot start animation");
    }
    lastUsage = std::chrono::steady_clock::now();
}

bool Animation::isPlaying() const {
    return std::chrono::steady_clock::now() - lastUsage < std::chrono::duration<double>(duration);
}

double Animation::getDuration() const {
    return duration;
}