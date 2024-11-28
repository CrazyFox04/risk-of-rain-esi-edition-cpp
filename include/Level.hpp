//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef LEVEL_HPP
#define LEVEL_HPP
#include <vector>
#include "Area.hpp"
#include "Areas.hpp"

class Level {
    static constexpr int MIN_LEVEL_SIZE = 3;
    static constexpr int MAX_LEVEL_SIZE = 7;
    int id;
    std::vector<std::vector<Area>> areas;

    void loadFromAreas(const std::vector<std::vector<Area>>&areas);

    static int generateLevelSize(int min, int max);

public:
    Level(int id);

    Level(int id, const std::vector<std::vector<Area>>&areas);

    int getId() const;

    bool isLoaded() const;

    Level generate();
};
#endif //LEVEL_HPP
