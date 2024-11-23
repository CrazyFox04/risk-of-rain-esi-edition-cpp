//
// Created by Enzo Renard on 19/11/2024.
//
#include <random>
#include "Area.hpp"

#include <Areas.hpp>

Area Area::getRandomArea() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, Areas.size());
    return Areas.at(dis(gen));
}
