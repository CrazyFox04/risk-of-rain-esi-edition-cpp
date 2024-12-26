//
// Created by Enzo Renard on 26/12/2024.
//

#ifndef JETPACK_HPP
#define JETPACK_HPP
#include <chrono>

class JetPack {
    double force;
    double maxTime;
    double cooldown;
    double landingAnimationTime;
    std::chrono::time_point<std::chrono::steady_clock> lastJetpackUse;

public:
    static constexpr double DEF_FORCE = 5.0;
    static constexpr double DEF_TIME = 5.0;
    static constexpr double DEF_COOLDOWN = 10.0;
    static constexpr double DEF_LANDING_ANIMATION_TIME = 0.2;

    JetPack(double force, double maxTime, double cooldown, double landingAnimationTime);

    void activate();

    bool canActivate() const;

    bool isUsing() const;

    double getForce() const;

    double getLandAnimationTime() const;

    double getMaxTime() const;
};
#endif //JETPACK_HPP
