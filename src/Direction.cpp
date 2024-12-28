//
// Created by Enzo Renard on 13/12/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Direction.hpp"
#include <stdexcept>

const Direction2D Direction::RIGHT = std::make_pair(1,0);
const Direction2D Direction::DOWN = std::make_pair(0,-1);
const Direction2D Direction::LEFT = std::make_pair(-1,0);
const Direction2D Direction::UP = std::make_pair(0,1);

Direction2D Direction::getOppositeDirection(Direction2D direction) {
    if (direction == UP) {
       return DOWN; 
    }
    if (direction == DOWN) {
        return UP;
    }
    if (direction == LEFT) {
        return RIGHT;
    }
    if (direction == RIGHT) {
        return LEFT;
    }
}
