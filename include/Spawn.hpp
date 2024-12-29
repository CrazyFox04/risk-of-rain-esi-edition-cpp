//
// Created by Enzo Renard on 25/12/2024.
//

#ifndef SPAWN_HPP
#define SPAWN_HPP
#include <chrono>

class Spawn {
    int id;
    std::chrono::time_point<std::chrono::steady_clock> lastTimeSpawned;
    double spawnCoolDown;
    bool boss;

    double get_random_spawn_cool_down(int min_spawn_cool_down, int max_spawn_cool_down);

public:
    Spawn(int id, int min_spawn_cool_down, int max_spawn_cool_down); 
    Spawn(int id, int min_spawn_cool_down, int max_spawn_cool_down, bool canSpawBoss);

    int getId() const;

    std::chrono::time_point<std::chrono::steady_clock> getLastTimeSpawned() const;

    bool canSpawn() const;

    bool canSpawnBoss() const;

    void spawnBoss();

    void spawn();
};
#endif //SPAWN_HPP
