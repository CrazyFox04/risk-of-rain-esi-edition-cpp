//
// Created by Enzo Renard on 26/12/2024.
//

#ifndef ATTACK_HPP
#define ATTACK_HPP
#include <string>

class Attack {
    std::string name;
    int damage;
    double cooldown;
    double chargeTime;
    double animationTime;
    std::chrono::time_point<std::chrono::steady_clock> lastUsageTime;

public:
    Attack(const std::string&name, int damage, double cooldown, double chargeTime, double animationTime);

    int use();

    bool isUsing() const;

    bool canUse() const;

    int getDamage() const;

    std::string getName() const;

    double getCooldown() const;

    double getChargeTime() const;

    double getAnimationTime() const;

    std::chrono::time_point<std::chrono::steady_clock> getLastUsageTime() const;

    bool operator<(const Attack&rhs) const {
        return name < rhs.name;
    }
};
#endif //ATTACK_HPP
