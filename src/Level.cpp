//
// Created by Enzo Renard on 19/11/2024.
//
#include "Direction.hpp"
#include "Level.hpp"

#include <random>

Level::Level(int id): id(id) {
}

Level::Level(int id, const std::vector<std::vector<Area>>&areas): id(id) {
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
    const int size_x = generateLevelSize(MIN_LEVEL_SIZE, MAX_LEVEL_SIZE);
    const int size_y = generateLevelSize(MIN_LEVEL_SIZE, MAX_LEVEL_SIZE);
    areas.resize(size_x);
    for (int i = 0; i < size_x; ++i) {
        areas[i].resize(size_y);
    }
    const int max_attempts = 100;
    for (int i = 0; i < size_x; ++i) {
        for (int j = 0; j < size_y; ++j) {
            if (i == 0 && j == 0) {
                areas[i][j] = Area::getRandomArea();
                continue;
            }
            Area newArea;
            bool compatible = false;
            int attempts = 0;
            while (!compatible && attempts < max_attempts) {
                newArea = Area::getRandomArea();
                compatible = true;
                if (i + Direction::UP.first >= 0 && j + Direction::UP.second >= 0 && i + Direction::UP.first < size_x && j + Direction::UP.second < size_y) {
                    compatible &= newArea.isCompatible(Direction::UP, areas[i + Direction::UP.first][j + Direction::UP.second]);
                }
                if (i + Direction::DOWN.first >= 0 && j + Direction::DOWN.second >= 0 && i + Direction::DOWN.first < size_x && j + Direction::DOWN.second < size_y) {
                    compatible &= newArea.isCompatible(Direction::DOWN, areas[i + Direction::DOWN.first][j + Direction::DOWN.second]);
                }
                if (i + Direction::LEFT.first >= 0 && j + Direction::LEFT.second >= 0 && i + Direction::LEFT.first < size_x && j + Direction::LEFT.second < size_y) {
                    compatible &= newArea.isCompatible(Direction::LEFT, areas[i + Direction::LEFT.first][j + Direction::LEFT.second]);
                }
                if (i + Direction::RIGHT.first >= 0 && j + Direction::RIGHT.second >= 0 && i + Direction::RIGHT.first < size_x && j + Direction::RIGHT.second < size_y) {
                    compatible &= newArea.isCompatible(Direction::RIGHT, areas[i + Direction::RIGHT.first][j + Direction::RIGHT.second]);
                }
                attempts++;
            }
            if (!compatible) {
                newArea = Area();
            }
            areas[i][j] = newArea;
        }
    }
    return std::move(*this); // todo : break the object WARNING -> need to add to docs
}

int Level::generateLevelSize(const int min, const int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max - 1);
    return dis(gen);
}

int Level::getId() const {
    return this->id;
}

int Level::getAreaID(int x, int y) const {
    return areas.at(x).at(y).getId();
}
