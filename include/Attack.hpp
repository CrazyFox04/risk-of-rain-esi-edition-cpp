//
// Created by Enzo Renard on 26/12/2024.
//
/**
 * @file Attack.hpp
 * @brief Defines the Attack class for handling character attacks.
 *
 * The Attack class manages all properties and logic for executing and controlling character attacks,
 * including damage, cooldowns, and animation times.
 */
#ifndef ATTACK_HPP
#define ATTACK_HPP
#include <string>
#include <chrono>

/**
 * @class Attack
 * @brief Represents an attack with configurable damage, cooldown, and animation timings.
 */
class Attack {
    std::string name; ///< The name of the attack.
    int damage; ///< The amount of damage dealt by the attack.
    double cooldown; ///< The cooldown time in seconds before the attack can be used again.
    double chargeTime; ///< The time required to charge the attack.
    double animationTime; ///< The duration of the attack's animation.
    std::chrono::time_point<std::chrono::steady_clock> lastUsageTime; ///< The last time the attack was used.

public:
    /**
     * @brief Constructs an Attack object with specified parameters.
     * @param name The name of the attack.
     * @param damage The amount of damage dealt.
     * @param cooldown The cooldown time in seconds.
     * @param chargeTime The time required to charge the attack.
     * @param animationTime The duration of the attack's animation.
     */
    Attack(const std::string&name, int damage, double cooldown, double chargeTime, double animationTime);

    /**
     * @brief Executes the attack and returns the damage dealt.
     * @throws std::runtime_error If the attack cannot be used.
     * @return The damage dealt by the attack.
     */
    int use();

    /**
     * @brief Checks if the attack is currently in use.
     * @return True if the attack is being used, otherwise false.
     */
    [[nodiscard]] bool isUsing() const;

    /**
     * @brief Checks if the attack can be used.
     * @return True if the attack can be used, otherwise false.
     */
    [[nodiscard]] bool canUse() const;

    /**
     * @brief Retrieves the damage dealt by the attack.
     * @return The damage value.
     */
    [[nodiscard]] int getDamage() const;

    /**
     * @brief Retrieves the name of the attack.
     * @return The name of the attack.
     */
    [[nodiscard]] std::string getName() const;

    /**
     * @brief Retrieves the cooldown time of the attack.
     * @return The cooldown time in seconds.
     */
    [[nodiscard]] double getCooldown() const;

    /**
     * @brief Retrieves the charge time of the attack.
     * @return The charge time in seconds.
     */
    [[nodiscard]] double getChargeTime() const;

    /**
     * @brief Retrieves the animation time of the attack.
     * @return The animation time in seconds.
     */
    [[nodiscard]] double getAnimationTime() const;

    /**
    * @brief Retrieves the last usage time of the attack.
    * @return A time_point representing the last usage time.
    */
    [[nodiscard]] std::chrono::time_point<std::chrono::steady_clock> getLastUsageTime() const;

    /**
     * @brief Compares two Attack objects based on their names.
     * @param rhs The other Attack object to compare with.
     * @return True if this attack's name is less than the other attack's name.
     */
    bool operator<(const Attack&rhs) const {
        return name < rhs.name;
    }

    /**
     * @brief Increases the damage dealt by the attack by a specified amount.
     * @param amount The amount by which to increase the damage.
     * @throws std::invalid_argument If the amount is negative.
     */
    void increaseDamage(double amount);
};
#endif //ATTACK_HPP
