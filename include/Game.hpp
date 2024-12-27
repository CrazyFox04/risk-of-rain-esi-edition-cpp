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
    int get_area_guid_current_level(int x, int y) const;

    /**
     * @brief Retrieves the player's maximum health.
     * @return The player's maximum health.
     */
    int getPlayerMaxHealth() const;

    /**
     * @brief Retrieves the player's current health.
     * @return The player's current health.
     */
    int getPlayerCurrentHealth() const;

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
    std::string getType(int id) const;

    /**
     * @brief Retrieves the speed of a character by ID.
     * @param id The character's ID.
     * @return The character's speed.
     */
    int getCharacterSpeed(int id) const;

    /**
     * @brief Retrieves the jump force of a character by ID.
     * @param id The character's ID.
     * @return The character's jump force.
     */
    double getCharacterJumpForce(int id) const;

    /**
     * @brief Retrieves the follow range of an enemy by ID.
     * @param id The enemy's ID.
     * @return The enemy's follow range.
     */
    double getEnemyFollowRange(int id) const;

    /**
     * @brief Retrieves the attack range of an enemy by ID.
     * @param id The enemy's ID.
     * @return The enemy's attack range.
     */
    double getEnemyAttackRange(int id) const;

    /**
     * @brief Checks if a character can use a given attack.
     * @param id The character's ID.
     * @param attackName The name of the attack.
     * @return True if the character can attack, otherwise false.
     */
    bool canCharacterAttack(int id, std::string attackName) const;

    /**
     * @brief Retrieves the damage of a character's attack.
     * @param id The ID of the character performing the attack.
     * @param attackName The name of the attack.
     * @return The damage dealt by the attack.
     */
    double getDamage(int id, std::string attackName) const;

    double getChargeTime(int id, std::string attackName) const;

    double getCharacterHurtTime(int id) const;

    bool isCharacterBusy(int id) const;

    int getCharacterHealth(int id) const;

    int getCharacterMaxHealth(int id) const;

    double getPlayerDashForce() const;

    double getJetPackForce() const;

    double getJetPackMaxTime() const;

    double getPlayerLandingTime() const;

    double getPlayerDashTime() const;

    double getCharacterAttackTime(int id, std::string attackName) const;

    bool isPlayerDashing() const;

    bool isPlayerUsingJetpack() const;

    bool canCharacterMove(int id, std::string movementName) const;

    double getCharacterCoolDownAttack(int id, std::string attackName) const;

    bool isAValidId(int id) const;

    int getPlayerId() const;

    std::tuple<std::tuple<int,int>, int> getExistingSpawn() const;

    static std::set<std::string> getCharacterAttacksName();

    static bool isAValidAttackName(std::string attackName) ;

    void attack(int id, std::string attackName, int targetId);

    void move(int id, std::string movementName);
};
#endif //GAME_HPP
