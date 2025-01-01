//
// Created by Enzo Renard on 26/12/2024.
//
/**
 * @file Movement.hpp
 * @brief Defines the Movement class, representing a generic movement capability in the game.
 *
 * The Movement class serves as a base class for different types of character movements. It includes
 * properties for force, animation time, and cooldown, and provides methods to check availability,
 * execute the movement, and retrieve movement details.
 */
#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP
#include <string>
#include <chrono>
#include "Movements.hpp"

/**
 * @class Movement
 * @brief Represents a base class for different movement types in the game.
 *
 * The Movement class manages the logic for cooldowns, animation times, and execution of movements.
 * Derived classes can override methods to implement specific movement behaviors.
 */
class Movement {
protected:
    std::string name; ///< The name of the movement (e.g., "JUMP", "RUN").
    double force; ///< The force applied during the movement.
    double animationTime; ///< The duration of the movement animation in seconds.
    double cooldown; ///< The cooldown time required before the movement can be used again.
    std::chrono::time_point<std::chrono::steady_clock> lastUsageTime; ///< The last time the movement was used.

public:
    virtual ~Movement() = default;

    /**
     * @brief Increases the force of the movement by a specified amount.
     * @param amount The amount to increase the force by.
     * @throws std::invalid_argument If the amount is negative.
     */
    void increaseForce(double amount);

    /**
     * @brief Constructs a Movement object with specified parameters.
     * @param name The name of the movement.
     * @param force The force applied during the movement.
     * @param animationTime The duration of the movement animation in seconds.
     * @param cooldown The cooldown time in seconds before the movement can be reused.
     */
    Movement(std::string name, double force, double animationTime, double cooldown);

    /**
     * @brief Checks if the movement is currently in use.
     * @return True if the movement is in use, otherwise false.
     */
    virtual bool isUsing() const;

    /**
     * @brief Checks if the movement can be used.
     * @return True if the movement can be executed, otherwise false.
     */
    [[nodiscard]] virtual bool canUse() const;

    /**
     * @brief Executes the movement and updates the last usage time.
     * @throws std::invalid_argument If the movement cannot be used due to cooldown or other constraints.
     */
    virtual void use();

    /**
     * @brief Stops the movement if it is currently active.
     * This method is intended to be overridden by derived class JetPack
     */
    virtual void stop();

    /**
     * @brief Retrieves the name of the movement.
     * @return The name of the movement as a string.
     */
    [[nodiscard]] std::string getName() const;

    /**
     * @brief Retrieves the force of the movement.
     * @return The force as a double.
     */
    [[nodiscard]] double getForce() const;

    /**
     * @brief Retrieves the animation time of the movement.
     * @return The animation time in seconds.
     */
    [[nodiscard]] double getAnimationTime() const;

    /**
     * @brief Retrieves the cooldown time of the movement.
     * @return The cooldown time in seconds.
     */
    [[nodiscard]] double getCooldown() const;

    /**
     * @brief Retrieves the last time the movement was used.
     * @return The time point of the last usage.
     */
    [[nodiscard]] std::chrono::time_point<std::chrono::steady_clock> getLastUsageTime() const;
};
#endif //MOVEMENT_HPP
