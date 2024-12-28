//
// Created by Enzo Renard on 26/12/2024.
//
/**
 * @file Run.hpp
 * @brief Defines the Run class, representing a running movement for characters in the game.
 *
 * The Run class is a specialized type of Movement that provides basic running functionality
 * with a configurable force.
 */
#ifndef RUN_HPP
#define RUN_HPP
#include "Movement.hpp"

/**
 * @class Run
 * @brief Represents a running movement for characters.
 *
 * The Run class extends the Movement class and is used to model a character's ability
 * to run with a specified force.
 */
class Run : public Movement {
    int running = false; ///< Flag indicating if the character is currently running.
public:
    /**
     * @brief Constructs a Run object with a specified force.
     * @param force The force applied during the running movement.
     */
    explicit Run(double force);
    void use() override;
    void stop() override;
    bool isUsing() const override;
    bool canUse() const override;
};

#endif //RUN_HPP
