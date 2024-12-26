//
// Created by Enzo Renard on 26/12/2024.
//

#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP
#include <string>

class Movement {
protected:
    std::string name;
    double force;
    double animationTime;
    double cooldown;
    std::chrono::time_point<std::chrono::steady_clock> lastUsageTime;

public:
    virtual ~Movement() = default;

    Movement(std::string name, double force, double animationTime, double cooldown);

    bool isUsing() const;

    virtual bool canUse() const;

    virtual void use();

    std::string getName() const;

    double getForce() const;

    double getAnimationTime() const;

    double getCooldown() const;

    std::chrono::time_point<std::chrono::steady_clock> getLastUsageTime() const;
};
#endif //MOVEMENT_HPP
