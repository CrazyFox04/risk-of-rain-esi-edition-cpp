//
// Created by Enzo Renard on 26/12/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Run.hpp"

Run::Run(double force) : Movement("RUN", force, 0, 0) {
}

void Run::use() {
    if (!canUse()) {
        throw std::invalid_argument("This movement is unavailable");
    }
    running = true;
}

void Run::stop() {
    running = false;
}

bool Run::isUsing() const {
    return running;
}

bool Run::canUse() const {
    return true;
}