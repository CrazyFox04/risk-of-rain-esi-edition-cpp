//
// Created by Enzo Renard on 19/11/2024.
//
/**
 * @file Enemy.hpp
 * @brief Defines the Enemy class, representing enemies in the game.
 *
 * The Enemy class is a specialized type of Character that includes additional attributes
 * and behavior specific to enemies, such as attack range, follow range, and boss status.
 */
#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "Character.hpp"

/**
 * @class Enemy
 * @brief Represents an enemy in the game, derived from the Character class.
 */
class Enemy : public Character {
    bool isBoss; ///< Indicates if the enemy is a boss.
    double followRange; ///< The distance within which the enemy follows the player.
    double attackRange; ///< The range within which the enemy can attack the player.

public:
    /**
     * @brief Constructs an Enemy object with specified attributes.
     * @param type The type or class of the enemy.
     * @param maxHealth The maximum health of the enemy.
     * @param followRange The follow range of the enemy.
     * @param attackRange The attack range of the enemy.
     * @param hurtTime The duration of the hurt animation for the enemy.
     * @param capabilities The capabilities (attacks, movements, etc.) of the enemy.
     * @param isBoss Indicates if the enemy is a boss.
     */
    Enemy(std::string type, int maxHealth, double followRange, double attackRange, double hurtTime,
          Capabilities capabilities, bool isBoss);

    /**
     * @brief Default destructor for the Enemy class.
     */
    ~Enemy() override = default;

    /**
     * @brief Retrieves the follow range of the enemy.
     * @return The follow range as a double.
     */
    [[nodiscard]] double getFollowRange() const;

    /**
     * @brief Retrieves the attack range of the enemy.
     * @return The attack range as a double.
     */
    [[nodiscard]] double getAttackRange() const;

    /**
     * @brief Checks if the enemy is a boss.
     * @return True if the enemy is a boss, otherwise false.
     */
    [[nodiscard]] bool getIsBoss() const;

    void addItem(Item buff) override;
};
#endif //ENEMY_HPP
