//
// Created by Enzo Renard on 26/12/2024.
//
/**
 * @file Health.hpp
 * @brief Defines the Health struct, representing a character's health in the game.
 *
 * The Health struct contains attributes to track the maximum and current health
 * of a character, enabling health management and updates during gameplay.
 */
#ifndef HEALTH_HPP
#define HEALTH_HPP
/**
 * @struct Health
 * @brief Represents the health of a character in the game.
 */
struct Health {
    int max; ///< The maximum health value for the character.
    int current; ///< The current health value of the character.
};
#endif //HEALTH_HPP
