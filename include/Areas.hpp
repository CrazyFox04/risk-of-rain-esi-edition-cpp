//
// Created by Enzo Renard on 22/11/2024.
//

#ifndef AREAS_HPP
#define AREAS_HPP
#include "AreaType.hpp"
#include "Area.hpp"

enum class Areas {
    BIOME1
};

static const auto Areas = std::vector<Area>{{{{}}, {1}, UNDERWATER}};
#endif //AREAS_HPP
