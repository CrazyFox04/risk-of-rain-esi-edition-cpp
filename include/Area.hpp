//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef AREA_HPP
#define AREA_HPP
#include <vector>
#include "AreaType.hpp"

class Area {
    std::vector<std::vector<Fragment>> fragments;
    std::vector<int> gatewayPositions;
    AreaType type;
};
#endif //AREA_HPP
