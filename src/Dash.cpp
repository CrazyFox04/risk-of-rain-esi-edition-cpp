//
// Created by Enzo Renard on 26/12/2024.
//

#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Dash.hpp"

Dash::Dash() : Movement("DASH", DEF_FORCE, DEF_ANIMATION_TIME, DEF_COOLDOWN) {
}

Dash::Dash(const double force, const double animationTime, const double cooldown) : Movement("DASH", force, animationTime, cooldown) {
}