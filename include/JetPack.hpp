//
// Created by Enzo Renard on 26/12/2024.
//

#ifndef JETPACK_HPP
#define JETPACK_HPP
#include <chrono>

class JetPack {
    double force;
    double maxFuel;
    double cooldown;
    double landingAnimationTime;
    double currentFuel;
    std::chrono::time_point<std::chrono::steady_clock> lastJetpackUse;
    std::chrono::time_point<std::chrono::steady_clock> jetpackRechargeStart;

public:
    static constexpr double DEF_FORCE = 5.0;
    static constexpr double DEF_TIME = 5.0;
    static constexpr double DEF_COOLDOWN = 10.0;
    static constexpr double DEF_LANDING_ANIMATION_TIME = 0.2;

    JetPack(double force, double maxFuel, double cooldown, double landingAnimationTime);

    void use();

    double getFuel() const;

    bool canUse() const;

    bool isUsing() const;

    bool isRecharging() const;
};
#endif //JETPACK_HPP
