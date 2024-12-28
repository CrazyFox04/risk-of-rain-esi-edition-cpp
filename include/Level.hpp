//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef LEVEL_HPP
#define LEVEL_HPP
#include <unordered_set>
#include <vector>
#include <map>
#include  "Enemy.hpp"
#include "Area.hpp"
#include "Areas.hpp"

class Level {
    int id;
    std::vector<std::vector<Area>> areas;
    std::map<int, Enemy> enemies;

    void loadFromAreas(const std::vector<std::vector<Area>>&areas);

public:
    static constexpr int HEIGHT = 3;
    static constexpr int LENGTH = 3;
    static constexpr float FILL_PROBABILITY = 0.05;

    explicit Level(int id);

    Level(int id, const std::vector<std::vector<Area>>&areas);

    [[nodiscard]] bool isValidCoordinates(int x, int y) const;

    [[nodiscard]] int getId() const;

    [[nodiscard]] bool isLoaded() const;

    Level generate();

    [[nodiscard]] int get_area_id(int x, int y) const;

    [[nodiscard]] int get_area_type(int x, int y) const;

    [[nodiscard]] int get_area_guid(int x, int y) const;

    [[nodiscard]] std::set<Direction2D> get_gateway_positions(int x, int y) const;

    bool can_spawn_at(int area_x, int area_y, int spawd_id);

    int spawn_at(int area_x, int area_y, int spawd_id);

    [[nodiscard]] Enemy getEnemy(int enemyId) const;

    [[nodiscard]] bool isAValidEnemyId(int id) const;

    [[nodiscard]] std::tuple<std::tuple<int,int>, int> getAnExistingSpawn() const;
};
#endif //LEVEL_HPP
