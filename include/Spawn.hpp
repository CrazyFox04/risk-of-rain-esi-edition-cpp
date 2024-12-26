//
// Created by Enzo Renard on 25/12/2024.
//

#ifndef SPAWN_HPP
#define SPAWN_HPP

class Spawn {
    int id;
    int lastTimeSpawned;
    int spawn_cool_down;

    int get_random_spawn_cool_down(int min_spawn_cool_down, int max_spawn_cool_down);

public:
    Spawn(int id, int min_spawn_cool_down, int max_spawn_cool_down);

    int getId() const;

    int getLastTimeSpawned() const;

    bool canSpawn() const;

    void spawn();
};
#endif //SPAWN_HPP
