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
    int spawn_at(int area_x, int area_y, int spawd_id);

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
};

#endif // LEVEL_HPP
