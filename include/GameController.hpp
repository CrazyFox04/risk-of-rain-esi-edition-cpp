//
// Created by Enzo Renard on 05/12/2024.
//
/**
 * @file GameController.hpp
 * @brief Defines the GameController class and C-style API for managing the game state and interactions.
 *
 * The GameController class acts as an interface to the Game class, exposing methods for
 * managing player and enemy states, querying game information, and controlling interactions.
 * A C-style API is also provided for external integration.
 */
#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#ifdef _WIN64
#define MY_API extern "C" __declspec(dllexport)
#else
#define MY_API extern "C"
#endif

#include "Game.hpp"

/**
 * @class GameController
 * @brief High-level interface to interact with the game logic.
 *
 * The GameController encapsulates an instance of the `Game` class, exposing methods to query and
 * modify the state of the game. It provides abstractions for player interactions, level management,
 * and combat/movement mechanics.
 */
class GameController {
    Game game_; ///< The core game instance managing levels, players, and enemies.

public:
    /**
     * @brief Gets the player's maximum health.
     * @return The maximum health of the player.
     */
    [[nodiscard]] int getPlayerMaxHealth() const;

    /**
     * @brief Gets the player's current health.
     * @return The current health of the player.
     */
    [[nodiscard]] int getPlayerCurrentHealth() const;

    /**
     * @brief Applies damage to the player.
     * @param damage The amount of damage to apply.
     */
    void takePlayerDamage(int damage);

    /**
     * @brief Gets the unique identifier for the area at a specific coordinate in the current level.
     * @param x The x-coordinate in the level.
     * @param y The y-coordinate in the level.
     * @return The GUID of the area, or -1 if invalid.
     */
    [[nodiscard]] int getAreaGuidCurrentLevel(int, int) const;

    /**
     * @brief Attempts to spawn an entity in the current level.
     * @param x The x-coordinate of the area.
     * @param y The y-coordinate of the area.
     * @param spawnId The ID of the spawn point.
     * @return The spawn result, or -1 if spawning is not possible.
     */
    int ifCanSpawnCurrentLevelSpawnAt(int, int, int);

    /**
     * @brief Gets the type of a character by ID.
     * @param id The unique ID of the character.
     * @return The type of the character as a string.
     */
    [[nodiscard]] std::string getType(int) const;

    /**
     * @brief Gets the speed of a character by ID.
     * @param id The unique ID of the character.
     * @return The speed of the character.
     */
    [[nodiscard]] double getCharacterSpeed(int) const;

    /**
     * @brief Gets the jump force of a character by ID.
     * @param id The unique ID of the character.
     * @return The jump force of the character.
     */
    [[nodiscard]] double getCharacterJumpForce(int) const;

    /**
     * @brief Gets the follow range of an enemy by ID.
     * @param id The unique ID of the enemy.
     * @return The follow range of the enemy.
     */
    [[nodiscard]] double getEnemyFollowRange(int) const;

    /**
     * @brief Gets the attack range of an enemy by ID.
     * @param id The unique ID of the enemy.
     * @return The attack range of the enemy.
     */
    [[nodiscard]] double getEnemyAttackRange(int) const;

    /**
     * @brief Checks if a character can attack with a specific attack.
     * @param id The unique ID of the character.
     * @param attackName The name of the attack.
     * @return True if the character can attack, otherwise false.
     */
    [[nodiscard]] bool canCharacterAttack(int, std::string) const;

    /**
     * @brief Gets the damage of a character's attack.
     * @param id The unique ID of the character.
     * @param attackName The name of the attack.
     * @return The damage dealt by the attack.
     */
    [[nodiscard]] int getDamage(int, std::string) const;

    /**
     * @brief Gets the charge time of a character's attack.
     * @param id The unique ID of the character.
     * @param attackName The name of the attack.
     * @return The charge time of the attack.
     */
    [[nodiscard]] double getChargeTime(int, std::string) const;

    /**
     * @brief Gets the hurt animation time of a character.
     * @param id The unique ID of the character.
     * @return The hurt animation time of the character.
     */
    [[nodiscard]] double getCharacterHurtTime(int) const;

    /**
     * @brief Gets the current health of a character by ID.
     * @param id The unique ID of the character.
     * @return The current health of the character.
     */
    [[nodiscard]] int getCharacterHealth(int) const;

    /**
     * @brief Gets the maximum health of a character by ID.
     * @param id The unique ID of the character.
     * @return The maximum health of the character.
     */
    [[nodiscard]] int getCharacterMaxHealth(int) const;

    /**
     * @brief Gets the dash force of the player.
     * @return The dash force of the player.
     */
    [[nodiscard]] double getPlayerDashForce() const;

    /**
     * @brief Gets the jetpack force of the player.
     * @return The jetpack force of the player.
     */
    [[nodiscard]] double getJetPackForce() const;

    /**
     * @brief Gets the maximum time the jetpack can be used.
     * @return The jetpack's maximum usage time.
     */
    [[nodiscard]] double getJetPackMaxTime() const;

    /**
     * @brief Gets the time taken for the player to land after using the jetpack.
     * @return The player's landing time.
     */
    [[nodiscard]] double getPlayerLandingTime() const;

    /**
     * @brief Gets the time taken for the player to dash.
     * @return The player's dash time.
     */
    [[nodiscard]] double getPlayerDashTime() const;

    /**
     * @brief Gets the entire time it take to a character to attack.
     * @param id The ID of the character performing the attack.
     * @param attackName The name of the attack.
     * @return The time of the attack.
     */
    [[nodiscard]] double getCharacterAttackTime(int, std::string) const;

    /**
     * @brief Checks if the player is currently dashing.
     * @return True if the player is dashing, otherwise false.
     */
    [[nodiscard]] bool isPlayerDashing() const;

    /**
     * @brief Checks if the player is currently using the jetpack.
     * @return True if the player is using the jetpack, otherwise false.
     */
    [[nodiscard]] bool isPlayerUsingJetpack() const;

    /**
     * @brief Checks if a character is not busy performing an action that would prevent movement.
     * @param id The unique ID of the character.
     * @param movementName The name of the movement.
     * @return True if the character can move, otherwise false.
     */
    [[nodiscard]] bool canCharacterMove(int, std::string) const;

    /**
     * @brief Gets the cooldown time of a character's attack.
     * @param id The unique ID of the character.
     * @param attackName The name of the attack.
     * @return The cooldown time of the attack.
     */
    [[nodiscard]] double getCharacterCoolDownAttackTime(int, std::string) const;

    /**
     * @brief Checks if a character ID is valid.
     * @param id The unique ID of the character.
     * @return True if the ID is valid, otherwise false.
     */
    [[nodiscard]] bool isAValidId(int) const;

    /**
     * @brief Gets the ID of the player character.
     * @return The ID of the player character.
     */
    [[nodiscard]] int getPlayerId() const;

    /**
     * @brief Attacks a target character with a specific attack.
     * @param id The unique ID of the attacking character.
     * @param attackName The name of the attack.
     * @param targetId The unique ID of the target character.
     */
    void attack(int, std::string, int);

    /**
     * @brief Moves a character with a specific movement.
     * @param id The unique ID of the character.
     * @param movementName The name of the movement.
     */
    void move(int, std::string);

    /**
     * @brief Checks if a character is currently busy performing an action.
     * @relatedalso Game::isCharacterBusy
     * @return True if the character is busy, otherwise false.
     */
    bool isCharacterBusy(int) const;

    /**
  * @brief Check if a character is on the ground.
  * @param id The ID of the character.
  * @return True if the character is on the ground, otherwise false.
  */
    bool isCharacterOnGround(int id) const;

    /**
     * @brief Changes the onGround status of the character.
     * @param id The ID of the character.
     */
    void landCharacter(int id);

    /**
     * @brief Changes the onGround status of the character.
     * @param id The ID of the character.
     */
    void takeOffCharacter(int id);
};

MY_API GameController* newGame();

MY_API void destroyGame(const GameController*);

MY_API int getPlayerMaxHealth(const GameController*);

MY_API int getPlayerCurrentHealth(GameController*);

MY_API void takePlayerDamage(GameController*, int);

MY_API int getAreaGuidCurrentLevel(const GameController*, int, int);

MY_API int ifCanSpawnCurrentLevelSpawnAt(GameController*, int, int, int);

MY_API const char* getType(const GameController*, int);

MY_API double getCharacterSpeed(const GameController*, int);

MY_API double getCharacterJumpForce(const GameController*, int);

MY_API double getEnemyFollowRange(const GameController*, int);

MY_API double getEnemyAttackRange(const GameController*, int);

MY_API bool canCharacterAttack_ATTACK1(const GameController*, int);

MY_API bool canCharacterAttack_ATTACK2(const GameController*, int);

MY_API bool canCharacterAttack_ATTACK3(const GameController*, int);

MY_API bool canCharacterAttack_ATTACK4(const GameController*, int);

MY_API bool canCharacterAttack_ATTACK5(const GameController*, int);

MY_API bool canCharacterAttack_ATTACK_SPECTRUM(const GameController*, int);

MY_API bool canCharacterAttack_ATTACK_MONSTER(const GameController*, int);

MY_API bool canCharacterAttack_ATTACK_DROID(const GameController*, int);

MY_API double getDamage_ATTACK1(const GameController*, int);

MY_API double getDamage_ATTACK2(const GameController*, int);

MY_API double getDamage_ATTACK3(const GameController*, int);

MY_API double getDamage_ATTACK4(const GameController*, int);

MY_API double getDamage_ATTACK5(const GameController*, int);

MY_API double getDamage_ATTACK_SPECTRUM(const GameController*, int);

MY_API double getDamage_ATTACK_MONSTER(const GameController*, int);

MY_API double getDamage_ATTACK_DROID(const GameController*, int);

MY_API double getChargeTime_ATTACK1(const GameController*, int);

MY_API double getChargeTime_ATTACK2(const GameController*, int);

MY_API double getChargeTime_ATTACK3(const GameController*, int);

MY_API double getChargeTime_ATTACK4(const GameController*, int);

MY_API double getChargeTime_ATTACK5(const GameController*, int);

MY_API double getChargeTime_ATTACK_SPECTRUM(const GameController*, int);

MY_API double getChargeTime_ATTACK_MONSTER(const GameController*, int);

MY_API double getChargeTime_ATTACK_DROID(const GameController*, int);

MY_API double getCharacterHurtTime(const GameController*, int);

MY_API int getCharacterHealth(const GameController*, int);

MY_API int getCharacterMaxHealth(const GameController*, int);

MY_API double getPlayerDashForce(const GameController*);

MY_API double getJetPackForce(const GameController*);

MY_API double getJetPackMaxTime(const GameController*);

MY_API double getPlayerLandingTime(const GameController*);

MY_API double getPlayerDashTime(const GameController*);

MY_API double getCharacterAttackTime_ATTACK1(const GameController*, int);

MY_API double getCharacterAttackTime_ATTACK2(const GameController*, int);

MY_API double getCharacterAttackTime_ATTACK3(const GameController*, int);

MY_API double getCharacterAttackTime_ATTACK4(const GameController*, int);

MY_API double getCharacterAttackTime_ATTACK5(const GameController*, int);

MY_API double getCharacterAttackTime_ATTACK_SPECTRUM(const GameController*, int);

MY_API double getCharacterAttackTime_ATTACK_MONSTER(const GameController*, int);

MY_API double getCharacterAttackTime_ATTACK_DROID(const GameController*, int);

MY_API bool isPlayerDashing(const GameController*);

MY_API bool isPlayerUsingJetpack(const GameController*);

MY_API bool canCharacterMove_RUN(const GameController*, int);

MY_API bool canCharacterMove_JUMP(const GameController*, int);

MY_API bool canCharacterMove_DASH(const GameController*, int);

MY_API double getCharacterCoolDownAttackTime_ATTACK1(const GameController*, int);

MY_API double getCharacterCoolDownAttackTime_ATTACK2(const GameController*, int);

MY_API double getCharacterCoolDownAttackTime_ATTACK3(const GameController*, int);

MY_API double getCharacterCoolDownAttackTime_ATTACK4(const GameController*, int);

MY_API double getCharacterCoolDownAttackTime_ATTACK5(const GameController*, int);

MY_API double getCharacterCoolDownAttackTime_ATTACK_SPECTRUM(const GameController*, int);

MY_API double getCharacterCoolDownAttackTime_ATTACK_MONSTER(const GameController*, int);

MY_API double getCharacterCoolDownAttackTime_ATTACK_DROID(const GameController*, int);

MY_API bool isAValidId(const GameController*, int);

MY_API int getPlayerId(const GameController*);

MY_API void attack_ATTACK1(GameController*, int, int);

MY_API void attack_ATTACK2(GameController*, int, int);

MY_API void attack_ATTACK3(GameController*, int, int);

MY_API void attack_ATTACK4(GameController*, int, int);

MY_API void attack_ATTACK5(GameController*, int, int);

MY_API void attack_ATTACK_SPECTRUM(GameController*, int, int);

MY_API void attack_ATTACK_MONSTER(GameController*, int, int);

MY_API void attack_ATTACK_DROID(GameController*, int, int);

MY_API void move_RUN(GameController*, int);

MY_API void move_JUMP(GameController*, int);

MY_API void move_DASH(GameController*, int);

MY_API bool isCharacterBusy(GameController*, int);

MY_API bool isCharacterOnGround(const GameController*, int);

MY_API void landCharacter(GameController*, int);

MY_API void takeOffCharacter(GameController*, int);

#endif
