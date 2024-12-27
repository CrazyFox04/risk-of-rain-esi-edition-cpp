//
// Created by Enzo Renard on 26/12/2024.
//

/**
 * @file Enemies.hpp
 * @brief Defines the Enemies enum and the DefinedEnemies struct for managing predefined enemies in the game.
 *
 * The Enemies enum lists predefined enemy types, while the DefinedEnemies struct provides functionality
 * to retrieve specific Enemy objects, generate random enemies, and access all enemy types.
 */

#ifndef ENEMIES_HPP
#define ENEMIES_HPP
#include <unordered_set>
#include "Enemy.hpp"

/**
 * @enum Enemies
 * @brief Represents predefined enemy types.
 */
enum Enemies {
    SPECTRUM,
    SMALL_MONSTER,
    SHIELD_DROID
};

/**
 * @struct DefinedEnemies
 * @brief Provides functionality to retrieve predefined Enemy objects and manage enemy types.
 */
struct DefinedEnemies {
    Enemy enemy; ///< The Enemy object representing a predefined enemy.

    /**
     * @brief Retrieves a predefined Enemy object based on the specified Enemies enum.
     * @param enemies The Enemies enum value representing the desired enemy.
     * @return A DefinedEnemies object containing the corresponding Enemy.
     * @throws std::invalid_argument If the enemy does not exist.
     */
    static DefinedEnemies get(const Enemies enemies);

    /**
     * @brief Retrieves the number of predefined enemy types.
     * @return The number of elements in the Enemies enum.
     */
    static int size();

    /**
     * @brief Retrieves all predefined enemy types.
     * @return An unordered set containing all Enemies enum values.
     */
    static std::unordered_set<Enemies> getAllEnemies();

    /**
     * @brief Retrieves a random enemy of the specified type (boss or non-boss).
     * @param isBoss Whether to retrieve a boss enemy (true) or a non-boss enemy (false).
     * @return A randomly selected Enemy object matching the specified type.
     * @throws std::runtime_error If no suitable enemy could be found.
     */
    static Enemy getRandomEnemy(bool isBoss);
};
#endif //ENEMIES_HPP
