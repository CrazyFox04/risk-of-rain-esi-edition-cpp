//
// Created by Enzo Renard on 19/11/2024.
//
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
    const int size_x = generateLevelSize(0,0);
    const int size_y = generateLevelSize(0,0);
    areas.resize(size_y);
    areas.at(0).resize(size_x);
    for (int i = 0; i < areas.size(); ++i) {
        for (int j = 0; j < areas.at(0).size(); ++j) {
            if (i == 0 && j == 0) {
                areas.at(i).at(j) = Area::getRandomArea();
            }
            auto newArea = Area::getRandomArea();
            const auto otherArea = areas.at(i).at(j);
            while (newArea.isCompatible(otherArea)) {
                newArea = Area::getRandomArea();
            }
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
