//
// Created by Enzo Renard on 28/12/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Climb.hpp"

Climb::Climb(double force) : Movement("CLIMB", force, 0, 0) {
}

void Climb::use() {
    if (!canUse()) {
        throw std::invalid_argument("This movement is unavailable");
    }
    climbing = true;
}

void Climb::stop() {
    climbing = false;
}

bool Climb::isUsing() const {
    return climbing;
}

bool Climb::canUse() const {
    return true;
}
