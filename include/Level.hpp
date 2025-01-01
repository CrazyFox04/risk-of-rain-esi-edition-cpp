//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef LEVEL_HPP
#define LEVEL_HPP
#include <vector>
#include <map>
#include "Enemy.hpp"
#include "Area.hpp"
#include "Areas.hpp"

/**
 * @class Level
 * @brief Represents a game level containing areas and enemies.
 */
class Level {
    int id; ///< Unique identifier for the level.
    std::vector<std::vector<Area>> areas; ///< 2D grid of areas in the level.
    std::map<int, Enemy> enemies; ///< Map of enemies in the level, keyed by their ID.

    /**
     * @brief Loads the level from a given set of areas.
     * @param areas 2D vector of areas to load into the level.
     */
    void loadFromAreas(const std::vector<std::vector<Area>>& areas);

    /**
     * @brief Gets a spawned enemy and applies a difficulty coefficient to its stats.
     * @param difficulty_coefficient The coefficient to apply to the enemy's stats.
     * @return The buffed enemy.
     * @throws std::invalid_argument If the difficulty coefficient is less than 1.0.
     */
    Enemy getARandomEnemy(double difficulty_coefficient);

public:
    static constexpr int HEIGHT = 3; ///< Height of the level grid.
    static constexpr int LENGTH = 3; ///< Length of the level grid.
    static constexpr float FILL_PROBABILITY = 0.05; ///< Probability of filling an area.

    /**
     * @brief Constructs a level with a given ID.
     * @param id Unique identifier for the level.
     */
    explicit Level(int id);

    /**
     * @brief Constructs a level with a given ID and areas.
     * @param id Unique identifier for the level.
     * @param areas 2D vector of areas to initialize the level with.
     */
    Level(int id, const std::vector<std::vector<Area>>& areas);

    /**
     * @brief Checks if the given coordinates are valid within the level grid.
     * @param x X-coordinate.
     * @param y Y-coordinate.
     * @return True if the coordinates are valid, false otherwise.
     */
    [[nodiscard]] bool isValidCoordinates(int x, int y) const;

    /**
     * @brief Gets the unique identifier of the level.
     * @return The level ID.
     */
    [[nodiscard]] int getId() const;

    /**
     * @brief Checks if the level is loaded.
     * @return True if the level is loaded, false otherwise.
     */
    [[nodiscard]] bool isLoaded() const;

    /**
     * @brief Generates a new level.
     * @return The generated level.
     */
    Level generate();

    /**
     * @brief Gets the ID of the area at the given coordinates.
     * @param x X-coordinate.
     * @param y Y-coordinate.
     * @return The area ID.
     */
    [[nodiscard]] int get_area_id(int x, int y) const;

    /**
     * @brief Gets the type of the area at the given coordinates.
     * @param x X-coordinate.
     * @param y Y-coordinate.
     * @return The area type.
     */
    [[nodiscard]] int get_area_type(int x, int y) const;

    /**
     * @brief Gets the GUID of the area at the given coordinates.
     * @param x X-coordinate.
     * @param y Y-coordinate.
     * @return The area GUID.
     */
    [[nodiscard]] int get_area_guid(int x, int y) const;

    /**
     * @brief Gets the gateway positions of the area at the given coordinates.
     * @param x X-coordinate.
     * @param y Y-coordinate.
     * @return A set of gateway positions.
     */
    [[nodiscard]] std::set<Direction2D> get_gateway_positions(int x, int y) const;

    /**
     * @brief Checks if an enemy can spawn at the given area coordinates with the given spawn ID.
     * @param area_x X-coordinate of the area.
     * @param area_y Y-coordinate of the area.
     * @param spawd_id Spawn ID.
     * @return True if the enemy can spawn, false otherwise.
     */
    bool can_spawn_at(int area_x, int area_y, int spawd_id);

    /**
     * @brief Spawns an enemy at the given area coordinates with the given spawn ID.
     * @param area_x X-coordinate of the area.
     * @param area_y Y-coordinate of the area.
     * @param spawd_id Spawn ID.
     * @return The ID of the spawned enemy.
     */
    int spawn_at(int area_x, int area_y, int spawd_id, double difficultyCoefficient);

    /**
     * @brief Gets the enemy with the given ID.
     * @param enemyId ID of the enemy.
     * @return The enemy.
     */
    [[nodiscard]] Enemy getEnemy(int enemyId) const;

    /**
     * @brief Checks if the given ID is a valid enemy ID.
     * @param id Enemy ID.
     * @return True if the ID is valid, false otherwise.
     */
    [[nodiscard]] bool isAValidEnemyId(int id) const;

    /**
     * @brief Gets an existing spawn point in the level.
     * @return A tuple containing the coordinates and spawn ID of an existing spawn point.
     */
    [[nodiscard]] std::tuple<std::tuple<int, int>, int> getAnExistingSpawn() const;

    /**
     * @brief Activates the boss spawn at a specific area and spawns a boss enemy.
     *
     * Checks the validity of the provided coordinates and spawn ID,
     * ensures that a boss can be spawned in the specified area, and then spawns a boss enemy.
     * @param area_x The x-coordinate of the area.
     * @param area_y The y-coordinate of the area.
     * @param area_id The ID of the spawn point within the area.
     * @return The ID of the spawned boss enemy.
     * @throws std::invalid_argument If the coordinates or spawn ID are invalid.
     * @throws std::runtime_error If a boss cannot be spawned in the specified area.
     */
    int activateBossSpawn(int area_x, int area_y, int area_id);

    /**
     * @brief Checks if a boss can be spawned at a specific area.
     * @param area_x The x-coordinate of the area.
     * @param area_y The y-coordinate of the area.
     * @param area_id The ID of the spawn point within the area.
     * @return True if a boss can be spawned, false otherwise.
     */
    bool canActivateBossSpawn(int area_x, int area_y, int area_id);

    /**
     * @brief Opens a chest at a specific area and retrieves the item inside.
     * @param area_x The x-coordinate of the area.
     * @param area_y The y-coordinate of the area.
     * @param chest_id The ID of the chest to open.
     * @return The item inside the chest.
     */
    Item openChest(int area_x, int area_y, int chest_id);

    /**
     * @brief Checks if a chest is empty at a specific area.
     * @param area_x The x-coordinate of the area.
     * @param area_y The y-coordinate of the area.
     * @param chest_id The ID of the chest to check.
     * @return True if the chest is empty, false otherwise.
     */
    bool isChestEmpty(int area_x, int area_y, int chest_id) const;

    /**
     * @brief Applies damage to an enemy identified by its ID.
     * @param id The ID of the enemy to damage.
     * @param damage The amount of damage to apply.
     * @Throws std::invalid_argument If the enemy ID is invalid.
     * @see Character::hurt(int damage)
     */
    void hurtEnemy(int id, int damage);

    /**
     * @brief Performs an attack on an enemy identified by its ID.
     * @param id The ID of the enemy to attack.
     * @param attackName The Name of the attack to perform.
     * @return The damage dealt to the enemy.
     */
    int attackEnemy(int id, std::string attackName);

    /**
     * @brief Unloads the level, removing all areas and enemies.
     */
    void unload();
};

#endif // LEVEL_HPP
