//
// Created by Enzo Renard on 19/11/2024.
//
/**
 * @file Game.hpp
 * @brief Defines the Game class, managing the overall game state, including levels, player, and interactions.
 *
 * The Game class handles the progression of levels, the state of the player, and the interactions
 * between the player and enemies, including movement, attacks, and health management.
 */
#ifndef GAME_HPP
#define GAME_HPP
#include <unordered_set>
#include <tuple>
#include "Player.hpp"

#include "Level.hpp"

#include <vector>

/**
 * @class Game
 * @brief Manages the overall game state, levels, player, and interactions.
 *
 * The Game class provides methods to control the game flow, including level progression,
 * player and enemy interactions, and game state queries.
 */
class Game {
    int activeLevel; ///< The index of the currently active level.
    std::vector<Level> levels; ///< A list of levels in the game.
    Player player; ///< The player character.

    /**
     * @brief Adds a new level to the game.
     * @param level The level to add.
     */
    void add_level(const Level&level);

    /**
     * @brief Progresses the game to the next level.
     */
    void next_level();

public:
    /**
     * @brief Constructs a new Game object, initializing levels and the player.
     */
    Game();

    /**
     * @brief Retrieves the currently active level.
     * @return The active Level object.
     */
    Level getActiveLevel();

    /**
     * @brief Retrieves the unique area identifier for a specific position in the current level.
     * @param x The x-coordinate of the position.
     * @param y The y-coordinate of the position.
     * @return The GUID of the area, or -1 if invalid.
     */
    [[nodiscard]] int get_area_guid_current_level(int x, int y) const;

    /**
     * @brief Retrieves the player's maximum health.
     * @return The player's maximum health.
     */
    [[nodiscard]] int getPlayerMaxHealth() const;

    /**
     * @brief Retrieves the player's current health.
     * @return The player's current health.
     */
    [[nodiscard]] int getPlayerCurrentHealth() const;

    /**
     * @brief Applies damage to the player.
     * @param damage The amount of damage to apply.
     */

    void takePlayerDamage(int damage);

    /**
     * @brief Attempts to spawn an entity in the current level.
     * @param areaX The x-coordinate of the area.
     * @param areaY The y-coordinate of the area.
     * @param spawdId The ID of the spawn point.
     * @return The spawn result, or -1 if unsuccessful.
     */
    int ifCanSpawnCurrentLevelSpawnAt(int areaX, int areaY, int spawdId);

    /**
     * @brief Retrieves the type of a character by ID.
     * @param id The character's ID.
     * @return The character's type as a string.
     */
    [[nodiscard]] int getCharacterType(int id) const;

    /**
     * @brief Retrieves the speed of a character by ID.
     * @param id The character's ID.
     * @return The character's speed.
     */
    [[nodiscard]] double getCharacterSpeed(int id) const;

    /**
     * @brief Retrieves the jump force of a character by ID.
     * @param id The character's ID.
     * @return The character's jump force.
     */
    [[nodiscard]] double getCharacterJumpForce(int id) const;

    /**
     * @brief Retrieves the follow range of an enemy by ID.
     * @param id The enemy's ID.
     * @return The enemy's follow range.
     */
    [[nodiscard]] double getEnemyFollowRange(int id) const;

    /**
     * @brief Retrieves the attack range of an enemy by ID.
     * @param id The enemy's ID.
     * @return The enemy's attack range.
     */
    [[nodiscard]] double getEnemyAttackRange(int id) const;

    /**
     * @brief Checks if a character can use a given attack.
     * @param id The character's ID.
     * @param attackName The name of the attack.
     * @return True if the character can attack, otherwise false.
     */
    [[nodiscard]] bool canCharacterAttack(int id, const std::string&attackName) const;

    /**
     * @brief Retrieves the damage of a character's attack.
     * @param id The ID of the character performing the attack.
     * @param attackName The name of the attack.
     * @return The damage dealt by the attack.
     */
    [[nodiscard]] int getDamage(int id, const std::string&attackName) const;

    /**
     * @brief Retrieves the charge time of a character's attack.
     * @param id The ID of the character performing the attack.
     * @param attackName The name of the
     * @return The charge time of the attack.
     */
    [[nodiscard]] double getChargeTime(int id, const std::string&attackName) const;

    /**
     * @brief Retrieves the hurt animation time of a character.
     * @param id The character's ID.
     * @return The character's hurt animation time.
     */
    [[nodiscard]] double getCharacterHurtTime(int id) const;

    /**
     * @brief Checks if a character is currently busy performing an action.
     * @param id The character's ID.
     * @return True if the character is busy, otherwise false.
     */
    [[nodiscard]] bool isCharacterBusy(int id) const;

    /**
     * @brief Retrieves the current health of a character by ID.
     * @param id The character's ID.
     * @return The character's current health.
     */
    [[nodiscard]] int getCharacterHealth(int id) const;

    /**
     * @brief Retrieves the maximum health of a character by ID.
     * @param id The character's ID.
     * @return The character's maximum health.
     */
    [[nodiscard]] int getCharacterMaxHealth(int id) const;

    /**
     * @brief Retrieves the dash force of the player.
     * @return The player's dash force.
     */
    [[nodiscard]] double getPlayerDashForce() const;

    /**
     * @brief Retrieves the jetpack force of the player.
     * @return The player's jetpack force.
     */
    [[nodiscard]] double getJetPackForce() const;

    /**
     * @brief Retrieves the maximum time the jetpack can be used.
     * @return The jetpack's maximum usage time.
     */
    [[nodiscard]] double getJetPackMaxTime() const;

    /**
     * @brief Retrieves the time taken for the player to land after using the jetpack.
     * @return The player's landing time.
     */
    [[nodiscard]] double getPlayerLandingTime() const;

    /**
     * @brief Retrieves the time taken for the player to dash.
     * @return The player's dash time.
     */
    [[nodiscard]] double getPlayerDashTime() const;

    /**
     * @brief Retrieves the entire time it take to a character to attack.
     * @param id The ID of the character performing the attack.
     * @param attackName The name of the attack.
     * @return The time of the attack.
     */
    [[nodiscard]] double getCharacterAttackTime(int id, std::string attackName) const;

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
     * @brief Checks if a character is not not performing any action that would prevent movement.
     * @param id The character's ID.
     * @param movementName The name of the movement.
     * @return True if the character can move, otherwise false.
     */
    [[nodiscard]] bool canCharacterMove(int id, const std::string&movementName) const;

    /**
     * @brief Retrieves the cooldown time of a character's attack.
     * @param id The ID of the character performing the attack.
     * @param attackName The name of the attack.
     * @return The cooldown time of the attack.
     */
    [[nodiscard]] double getCharacterCoolDownAttack(int id, std::string attackName) const;

    /**
     * @brief Checks if a given ID is valid.
     * @param id The ID to check.
     * @return True if the ID is valid, otherwise false.
     */
    [[nodiscard]] bool isAValidId(int id) const;

    /**
     * @brief Retrieves the player's ID.
     * @return The player's ID.
     */
    [[nodiscard]] int getPlayerId() const;

    /**
     * @brief Retrieves an existing spawn point in the current level.
     * @return The spawn point as a tuple of area coordinates and spawn ID.
     */
    [[nodiscard]] std::tuple<std::tuple<int, int>, int> getExistingSpawn() const;

    int activateBossSpawn(int area_x, int area_y, int area_id);

    /**
     * @brief Retrieves the names of all character attacks.
     * @return A set of attack names.
     */
    static std::set<std::string> getCharacterAttacksName();

    /**
     * @brief Checks if a given attack name is valid.
     * @param attackName The name of the attack.
     * @return True if the attack name is valid, otherwise false.
     */
    static bool isAValidAttackName(const std::string&attackName);

    static bool isAValidMovementName(const std::string&string);

    /**
     * @brief Attacks a target character with a specific attack.
     * @param id The ID of the attacking character.
     * @param attackName The name of the attack.
     * @param targetId The ID of the target character.
     * @throws std::invalid_argument If the attack is invalid or the ids are not valid.
     */
    void attack(int id, std::string attackName, int targetId);

    /**
     * @brief Moves a character using a specific movement.
     * @param id The ID of the character to move.
     * @param movementName The name of the movement.
     * @throws std::invalid_argument If the movement is invalid or the ID is not valid.
     */
    void move(int id, const std::string&movementName);

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

    int getMovingType(int id) const;

    int isMoving(int id) const;

    void stopMoving(int id, std::string type);
};
#endif //GAME_HPP
