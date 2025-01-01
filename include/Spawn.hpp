//
// Created by Enzo Renard on 25/12/2024.
//

#ifndef SPAWN_HPP
#define SPAWN_HPP
#include <chrono>

/**
 * @class Spawn
 * @brief Represents a spawn point for enemies or bosses in the game.
 *
 * The Spawn class manages spawn cooldowns, supports spawning bosses, and provides
 * utility methods for spawn management.
 */
class Spawn {
    int id; ///< The unique identifier for the spawn point.
    std::chrono::time_point<std::chrono::steady_clock> lastTimeSpawned; ///< The last time an enemy was spawned.
    double spawnCoolDown; ///< The cooldown duration between spawns.
    bool boss; ///< Flag indicating if the spawn point can spawn bosses.


    double get_random_spawn_cool_down(int min_spawn_cool_down, int max_spawn_cool_down);

public:
    Spawn(int id, int min_spawn_cool_down, int max_spawn_cool_down); 
    Spawn(int id, int min_spawn_cool_down, int max_spawn_cool_down, bool canSpawBoss);

    /**
     * @brief Retrieves the unique identifier for the spawn point.
     * @return The ID of the spawn point.
     */
    int getId() const;

    /**
     * @brief Retrieves the last time an enemy was spawned.
     * @return The time point of the last spawn.
     */
    std::chrono::time_point<std::chrono::steady_clock> getLastTimeSpawned() const;

    /**
     * @Brief Checks if the spawn point is ready to spawn an enemy.
     * @return True if the cooldown has passed or no enemy has been spawned yet, false otherwise.
     */
    bool canSpawn() const;

    /**
     * @brief Checks if the spawn point can spawn a boss.
     * @return the boss flag.
     */
    bool canSpawnBoss() const;

    /**
     * @brief Spawns a Boss and disables further boss spawning.
     * @throws std::runtime_error if the spawn point can't spawn a boss.
     */
    void spawnBoss();

    /**
     * @brief Spawns an enemy at the spawn point and updates the last spawn time.
     * @throws std::runtime_error if the spawn point is not ready to spawn.
     */
    void spawn();
};
#endif //SPAWN_HPP
