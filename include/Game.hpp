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
    bool over; ///< Flag indicating if the game is over.
    double difficulty = 1.0; ///< Coefficient to adjust the difficulty of the game.
    std::chrono::time_point<std::chrono::steady_clock> timeSinceDifficultyUpdate; ///< Record of Difficulty Update

    static constexpr auto DIFFICULTY_INTERVAL = std::chrono::seconds(300); ///< Interval for difficulty updates.

    /**
     * @brief Updates the difficulty coefficient of the game.
     * @param increment The amount to increase the difficulty coefficient by.
     * @throws std::invalid_argument If the increment is negative.
     */
    void increaseDifficulty(double increment);

    /**
     * @brief Updates the game difficulty based on a predefined interval.
     */
    void updateGameDifficulty();

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
     * @brief Constructs a new Game object with chosen attacks for the player.
     * @param primaryAttack The enum index of primary attack for the player.
     * @param secondaryAttack The enum index of the secondary attack for the player.
     * @param tertiaryAttack The enum index of the tertiary attack for the player.
     */
    Game(int primaryAttack, int secondaryAttack, int tertiaryAttack);

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
    [[nodiscard]] double getCharacterAttackTime(int id, const std::string& attackName) const;

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
    [[nodiscard]] double getCharacterCoolDownAttack(int id, const std::string& attackName) const;

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

    /**
     * @brief Activates a boss spawn in the current level.
     * @param areaX The x-coordinate of the area.
     * @param areaY The y-coordinate of the area.
     * @param area_id The ID of the spawn point.
     * @return The ID of the spawned boss, or -1 if the spawn is not possible.
     */
    int activateBossSpawn(int area_x, int area_y, int area_id);

    /**
     * @brief Checks if a boss spawn can be activated in the current level.
     * @param areaX The x-coordinate of the area.
     * @param areaY The y-coordinate of the area.
     * @param spawnId The ID of the spawn point.
     * @return True if the boss spawn can be activated, otherwise false.
     */
    bool canActivateBossSpawn(int areaX, int areaY, int spawnId);

    /**
     * @brief Retrieves the time a character has to wait to use a movement again.
     * @param id The ID of the character.
     * @param movementName The name of the movement.
     * @return The cooldown of the movement.
     */
    double getCharacterCoolDownMovementTime(int id, const std::string&string) const;

    /**
     * Checks if a chest in a specific area has been opened.
     * @param area_x The x-coordinate of the area.
     * @param area_y The y-coordinate of the area.
     * @param chest_id The ID of the chest to check.
     * @return True if the chest is empty, otherwise false.
     */
    bool isChestEmpty(int area_x, int area_y, int chest_id) const;

    /**
     * @brief Opens a chest in a specific area.
     * @param area_x The x-coordinate of the area.
     * @param area_y The y-coordinate of the area.
     * @param chest_id The ID of the chest to open.
     * @return The ID of the item found in the chest.
     */
    int openChest(int area_x, int area_y, int chest_id);

    /**
     * @brief Retrieves the number of a specific item in the player's inventory.
     * @param id The ID of the player.
     * @param item_id The ID of the item to check.
     * @return The number of the item in the player's inventory.
     */
    int getNumberOfItem(int id, int item_id) const;

    bool canEndCurrentLevel(int bossId) const;

    void useHealthPotionIfAvailable();

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

    /**
     * @brief Checks if a given movement name is valid.
     * @param string The name of the movement.
     * @return True if the movement name is valid, otherwise false.
     */
    static bool isAValidMovementName(const std::string&string);

    /**
     * @brief Attacks a target character with a specific attack.
     * @param id The ID of the attacking character.
     * @param attackName The name of the attack.
     * @param targetId The ID of the target character.
     * @throws std::invalid_argument If the attack is invalid or the ids are not valid.
     */
    void attack(int id, const std::string& attackName, int targetId);

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

    /**
     * @brief Retrieves th movement type of a character by ID.
     * @param id The ID of the character moving
     * @return The index value of the movement in the enum.
     */
    int getMovingType(int id) const;

    /**
     * @brief Checks if a character is moving.
     * @param id The ID of the character.
     * @return The index value of the movement in the enum if moving, -1 otherwise.
     */
    int isMoving(int id) const;

    /**
     * @brief Manually stops a movement. Designed for the JetPack.
     * @param id The ID of the character who needs to stop moving.
     * @param type The movement type to stop.
     */
    void stopMoving(int id, const std::string& type);

    /**
     * @brief Retrieves the current difficulty coefficient of the game.
     * @return The difficulty coefficient.
     */
    double getDifficulty() const;

    /**
     * @brief Checks if the game is over.
     * @return True if the game is over, otherwise false.
     */
    [[nodiscard]] bool isOver() const;

    /**
     * @brief Retrieves the primary attack of the player.
     * @return The primary attack enum index.
     */
    int getPrimaryPlayerAttack() const;

    /**
     * @brief Retrieves the secondary attack of the player.
     * @return The secondary attack enum index.
     */
    int getSecondaryPlayerAttack() const;

    /**
     * @brief Retrieves the tertiary attack of the player.
     * @return The tertiary attack enum index.
     */
    int getTertiaryPlayerAttack() const;

    /**
     * @brief Progresses the game to the next level.
     * @param bossId The ID of the current level's boss.
     * @throws std::runtime_error If the level cannot be ended.
     */
    void nextLevel(int bossId);
};
#endif //GAME_HPP
