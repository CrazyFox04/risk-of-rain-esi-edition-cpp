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

void Level::generate() {
    if (this->isLoaded()) {
        throw std::runtime_error("Cannot generate an already loaded level : void generate()");
    }
    int size = generateLevelSize(0,0);
}

int Level::generateLevelSize(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max - 1);
    return dis(gen);
}
