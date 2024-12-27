//
// Created by Enzo Renard on 26/12/2024.
//
/**
 * @file Dash.hpp
 * @brief Defines the Dash class, a movement type that allows characters to perform a quick dash.
 *
 * The Dash class inherits from the Movement class and provides a specialized movement
 * with configurable force, animation time, and cooldown.
 */
#ifndef DASH_HPP
#define DASH_HPP
#include "Movement.hpp"

/**
 * @class Dash
 * @brief Represents a dash movement, allowing a character to quickly move forward with a burst of speed.
 */
class Dash : public Movement {
public:
    static constexpr double DEF_FORCE = 1000.0; ///< Default force applied during the dash.
    static constexpr double DEF_ANIMATION_TIME = 0.4; ///< Default duration of the dash animation in seconds.
    static constexpr double DEF_COOLDOWN = 5.0; ///< Default cooldown time before the dash can be used again.

    /**
     * @brief Constructs a Dash object with default parameters.
     *
     * Default parameters are:
     * - Force: `DEF_FORCE`
     * - Animation time: `DEF_ANIMATION_TIME`
     * - Cooldown: `DEF_COOLDOWN`
     */
    Dash();

    /**
     * @brief Constructs a Dash object with specified parameters.
     * @param force The force applied during the dash.
     * @param animationTime The duration of the dash animation in seconds.
     * @param cooldown The cooldown time in seconds before the dash can be used again.
     */
    Dash(double force, double animationTime, double cooldown);
};
#endif //DASH_HPP
