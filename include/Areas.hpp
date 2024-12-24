// include/Areas.hpp

#ifndef AREAS_HPP
#define AREAS_HPP
#include "Direction.hpp"
#include "Area.hpp"
#define end_value 999999

enum Areas {
    A1U,
    A1R,
    A1D,
    A1L,
    A2UR,
    A2LD,
    A2UL,
    A2DR,
    A2UD,
    A2LR,
    A3LUR,
    A3URD,
    A3LDR,
    A3ULD,
    A4URDL = end_value
};

struct DefinedAreas {
    Area area;

    static DefinedAreas get(const Areas areas) {
        switch (areas) {
            case A1U:
                return DefinedAreas{Area(1, 1, {Direction::UP})};
            case A1R:
                return DefinedAreas{Area(2, 1, {Direction::RIGHT})};
            case A1D:
                return DefinedAreas{Area(3, 1, {Direction::DOWN})};
            case A1L:
                return DefinedAreas{Area(4, 1, {Direction::LEFT})};
            case A2UR:
                return DefinedAreas{Area(5, 1, {Direction::UP, Direction::RIGHT})};
            case A2LD:
                return DefinedAreas{Area(6, 1, {Direction::LEFT, Direction::DOWN})};
            case A2UL:
                return DefinedAreas{Area(7, 1, {Direction::UP, Direction::LEFT})};
            case A2DR:
                return DefinedAreas{Area(8, 1, {Direction::DOWN, Direction::RIGHT})};
            case A2UD:
                return DefinedAreas{Area(9, 1, {Direction::UP, Direction::DOWN})};
            case A2LR:
                return DefinedAreas{Area(10, 1, {Direction::LEFT, Direction::RIGHT})};
            case A3LUR:
                return DefinedAreas{Area(11, 1, {Direction::UP, Direction::LEFT, Direction::RIGHT})};
            case A3URD:
                return DefinedAreas{Area(12, 1, {Direction::UP, Direction::RIGHT, Direction::DOWN})};
            case A3LDR:
                return DefinedAreas{Area(13, 1, {Direction::LEFT, Direction::DOWN, Direction::RIGHT})};
            case A3ULD:
                return DefinedAreas{Area(14, 1, {Direction::UP, Direction::LEFT, Direction::DOWN})};
            case A4URDL:
                return DefinedAreas{Area(15, 2, {Direction::UP, Direction::RIGHT, Direction::DOWN, Direction::LEFT})};
            default:
                return DefinedAreas{Area()};
        }
    }

    static int size() {
        int count = 0;
        for (int i = 0; i < end_value; ++i) {
            if (get(static_cast<Areas>(i)).area.get_type() != -1) {
                ++count;
            }
            else {
                break;
            }
        }
        return ++count;
    }
};

#endif //AREAS_HPP
