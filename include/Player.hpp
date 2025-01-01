//
// Created by Enzo Renard on 19/11/2024.
//
/**
 * @file Player.hpp
 * @brief Defines the Player class, representing the playable character in the game.
 *
 * The Player class is a specialized type of Character with predefined health,
 * movements, and attacks. It also includes functionality to manage items (buffs).
 */
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <chrono>
#include <string>
#include <set>
#include <array>
#include "Dash.hpp"
#include "Jump.hpp"
#include "Run.hpp"

#include "Capabilities.hpp"
#include "Health.hpp"
#include "Character.hpp"

/**
 * @class Player
 * @brief Represents the player-controlled character in the game.
 *
 * The Player class extends the Character class and includes default configurations for
 * health, movements, and attacks. It also supports managing items (buffs).
 */
class Player : public Character {
public:
    static constexpr int DEF_MAX_HEALTH = 100; ///< Default maximum health for the player.
    static constexpr double DEF_RUN_FORCE = 4.0; ///< Default force for running movements.
    static constexpr double DEF_JUMP_FORCE = 6.0; ///< Default force for jumping movements.
    static constexpr double DEF_HURT_TIME = 0.5; ///< Default duration of the hurt animation.
    static constexpr double DEF_CLIMB_FORCE = 4.0;
    static const std::vector<Attack> DEF_ATTACKS_PLAYER; ///< Default set of attacks available to the player.

    /**
     * @brief Constructs a Player object with default health, movements, and attacks.
     */
    Player();

    Player(int primaryAttack, int secondaryAttack, int tertiaryAttack);

    void die() override;

    ~Player() override = default;

    void useHealthPotion();
};

#endif //PLAYER_HPP
