//
// Created by Enzo Renard on 26/12/2024.
//

#ifndef DASH_HPP
#define DASH_HPP
#include "Movement.hpp"

class Dash : public Movement {
public:
    static constexpr double DEF_FORCE = 1000.0;
    static constexpr double DEF_ANIMATION_TIME = 0.4;
    static constexpr double DEF_COOLDOWN = 5.0;

    Dash();
    Dash(double force, double animationTime, double cooldown);
};
#endif //DASH_HPP
