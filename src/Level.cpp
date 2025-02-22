//
// Created by Enzo Renard on 19/11/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Level.hpp"

#include "Enemies.hpp"

#include "Direction.hpp"
#include <random>
#include <stdexcept>
#include <functional>
#include <utility>

Level::Level(const int id): id(id) {
}

Level::Level(const int id, const std::vector<std::vector<Area>>&areas): id(id) {
    loadFromAreas(areas);
}

void Level::loadFromAreas(const std::vector<std::vector<Area>>&areas) {
    if (areas.empty()) {
        throw std::invalid_argument("No areas specified : Level::loadFromAreas(std::vector<std::vector<Area>> areas)");
    }
    if (isLoaded()) {
        throw std::runtime_error(
            "Cannot load an already loaded level : Level::loadFromAreas(std::vector<std::vector<Area>> areas)");
    }
    for (const auto&area: areas) {
        this->areas.push_back(area);
    }
}

bool Level::isLoaded() const {
    return !this->areas.empty();
}

Level Level::generate() {
    if (this->isLoaded()) {
        throw std::runtime_error("Cannot generate an already loaded level : Level generate()");
    }
    areas.resize(LENGTH);
    for (int i = 0; i < LENGTH; ++i) {
        areas[i].resize(HEIGHT);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < LENGTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            if (dis(gen) < FILL_PROBABILITY) {
                areas[i][j] = Area(0, 1, {});
            }
        }
    }

    areas[0][0] = Area();
    areas[1][1] = DefinedAreas::get(A4URDL).area;

    std::function<bool(int, int)> backtrack = [&](int x, int y) {
        if (x == LENGTH) return true;
        if (y == HEIGHT) return backtrack(x + 1, 0);

        if (areas[x][y].get_type() == 0 || areas[x][y].get_type() == 40) return backtrack(x, y + 1);

        std::vector<Area> candidates;
        for (int i = 0; i < DefinedAreas::size(); ++i) {
            Area candidate = DefinedAreas::get(static_cast<Areas>(i)).area;
            bool compatible = true;

            if (x > 0 && areas[x - 1][y].get_type() != 0) {
                compatible &= candidate.isCompatible(Direction::LEFT, areas[x - 1][y]);
            }
            else {
                compatible &= candidate.isCompatible(Direction::LEFT, Area(0, 1, {}));
            }
            if (y < HEIGHT - 1 && areas[x][y + 1].get_type() != 0) {
                compatible &= candidate.isCompatible(Direction::UP, areas[x][y + 1]);
            }
            else {
                compatible &= candidate.isCompatible(Direction::UP, Area(0, 1, {}));
            }
            if (x < LENGTH - 1 && areas[x + 1][y].get_type() != 0) {
                compatible &= candidate.isCompatible(Direction::RIGHT, areas[x + 1][y]);
            }
            else {
                compatible &= candidate.isCompatible(Direction::RIGHT, Area(0, 1, {}));
            }
            if (y > 0 && areas[x][y - 1].get_type() != 0) {
                compatible &= candidate.isCompatible(Direction::DOWN, areas[x][y - 1]);
            }
            else {
                compatible &= candidate.isCompatible(Direction::DOWN, Area(0, 1, {}));
            }

            if (compatible) {
                candidates.push_back(candidate);
            }
        }

        std::ranges::shuffle(candidates, gen);

        for (const auto&candidate: candidates) {
            areas[x][y] = candidate;
            if (backtrack(x, y + 1)) return true;
        }

        return false;
    };

    if (!backtrack(0, 0)) {
        for (int i = 0; i < LENGTH; ++i) {
            for (int j = 0; j < HEIGHT; ++j) {
                if (areas[i][j].get_type() == -1) {
                    areas[i][j] = Area(0, 1, {});
                }
            }
        }
    }

    return std::move(*this);
}

int Level::getId() const {
    return this->id;
}

int Level::get_area_type(const int x, const int y) const {
    return areas.at(x).at(y).get_type();
}

int Level::get_area_id(const int x, const int y) const {
    return areas.at(x).at(y).get_id();
}

int Level::get_area_guid(const int x, const int y) const {
    if (!isLoaded()) {
        throw std::runtime_error("Cannot get guid of an unloaded level");
    }
    if (!isValidCoordinates(x, y)) {
        throw std::invalid_argument("Invalid area coordinates (" + std::to_string(x) + ", " + std::to_string(y) + ")");
    }
    return areas.at(x).at(y).get_guid();
}

std::set<Direction2D> Level::get_gateway_positions(const int x, const int y) const {
    return areas.at(x).at(y).get_gateway_positions();
}

bool Level::can_spawn_at(const int area_x, const int area_y, const int spawnId) {
    return areas.at(area_x).at(area_y).can_spawn(spawnId);
}

int Level::spawn_at(const int area_x, const int area_y, const int spawnId, const double difficultyCoefficient) {
    if (!can_spawn_at(area_x, area_y, spawnId)) {
        throw std::invalid_argument(
            "Cannot spawn at area (" + std::to_string(area_x) + ", " + std::to_string(area_y) + ") with spawn id " +
            std::to_string(spawnId));
    }
    areas.at(area_x).at(area_y).spawn(spawnId);
    auto enemy = getARandomEnemy(difficultyCoefficient);
    enemies.emplace(enemy.getId(), enemy);
    return enemy.getId();
}

Enemy Level::getEnemy(const int enemyId) const {
    if (!enemies.contains(enemyId)) {
        throw std::invalid_argument("No enemy with id " + std::to_string(enemyId));
    }
    return enemies.at(enemyId);
}

bool Level::isAValidEnemyId(const int id) const {
    return enemies.contains(id);
}

bool Level::isValidCoordinates(const int x, const int y) {
    return x >= 0 && x < LENGTH && y >= 0 && y < HEIGHT; 
}

std::tuple<std::tuple<int, int>, int> Level::getAnExistingSpawn() const {
    for (int i = 0; i < LENGTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            if (areas[i][j].get_type() != 0 && !areas[i][j].get_spawn_ids().empty()) {
                return std::make_tuple(std::make_tuple(i, j), areas[i][j].get_spawn_ids().at(0));
            }
        }
    }
    return std::make_tuple(std::make_tuple(-1, -1), -1);
}

int Level::activateBossSpawn(const int area_x, const int area_y, const int area_id) {
    if (!isValidCoordinates(area_x, area_y)) {
        throw std::invalid_argument(
            "Invalid area coordinates (" + std::to_string(area_x) + ", " + std::to_string(area_y) + ")");
    }
    if (!areas.at(area_x).at(area_y).can_spawn(area_id)) {
        throw std::invalid_argument(
            "Cannot spawn at area (" + std::to_string(area_x) + ", " + std::to_string(area_y) + ") with spawn id " +
            std::to_string(area_id));
    }
    if (!areas.at(area_x).at(area_y).canSpawnBoss()) {
        throw std::runtime_error(
            "Cannot spawn boss at area (" + std::to_string(area_x) + ", " + std::to_string(area_y) + ")");
    }
    areas.at(area_x).at(area_y).spawnBoss(area_id);
    Enemy enemy = DefinedEnemies::getRandomEnemy(true);
    enemies.emplace(enemy.getId(), enemy);
    return enemy.getId();
}

bool Level::canActivateBossSpawn(const int area_x, const int area_y) const {
    return areas.at(area_x).at(area_y).canSpawnBoss();
}

bool Level::isChestEmpty(const int area_x, const int area_y, const int chest_id) const {
    return areas.at(area_x).at(area_y).isChestEmpty(chest_id);
}

Item Level::openChest(const int area_x, const int area_y, const int chest_id) {
    return areas.at(area_x).at(area_y).openChest(chest_id);
}

void Level::hurtEnemy(const int id, const int damage) {
    if (!enemies.contains(id)) {
        throw std::invalid_argument("No enemy with id " + std::to_string(id));
    }
    enemies.at(id).hurt(damage);
}

int Level::attackEnemy(const int id, const std::string& attackName) {
    if (!enemies.contains(id)) {
        throw std::invalid_argument("No enemy with id " + std::to_string(id));
    }
    return enemies.at(id).attack(attackName);
}

Enemy Level::getARandomEnemy(double difficulty_coefficient) {
    if (difficulty_coefficient < 1.0) {
        throw std::invalid_argument("Difficulty coefficient must be greater than or equal to 1.0");
    }
    Enemy enemy = DefinedEnemies::getRandomEnemy(false);
    enemy.increaseMaxHealth(enemy.getHealth().max * difficulty_coefficient - enemy.getHealth().max);
    for (const auto& attack_name: enemy.getAllAttackName()) {
        const auto amount = enemy.getAttack(attack_name).getDamage() * difficulty_coefficient - enemy.getAttack(attack_name).
                      getDamage();
        enemy.increaseAttackDamage(amount, {attack_name});
    }
    enemy.increaseMovementForce(
        "RUN", enemy.getMovement("RUN")->getForce() * difficulty_coefficient - enemy.getMovement("RUN")->getForce());
    return enemy;
}

void Level::unload() {
    enemies = {};
    areas = {};
}
