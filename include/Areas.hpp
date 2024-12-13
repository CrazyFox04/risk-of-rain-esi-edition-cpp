// include/Areas.hpp

#ifndef AREAS_HPP
#define AREAS_HPP
#include "Direction.hpp"
#include "Area.hpp"
#define end_value 999999

enum Areas {
    BIOME1,
    BIOME2,
    BIOME3,
    BIOME4,
    BIOME5, 
    BIOME6 = end_value
};

struct DefinedAreas {
    Area area;

    static DefinedAreas get(Areas areas) {
        switch (areas) {
            case BIOME1:
                return {{1, {Direction::DOWN, Direction::UP}}};
            case BIOME2:
                return {{2 , {Direction::DOWN, Direction::UP, Direction::LEFT, Direction::RIGHT}}};
            case BIOME3: 
                return {{3, {Direction::LEFT, Direction::RIGHT}}};
            case BIOME4:
                return {{4, {Direction::UP, Direction::DOWN, Direction::LEFT}}};
            case BIOME5:
                return {{5, {Direction::UP, Direction::RIGHT}}};
            case BIOME6:
                return {{6, {Direction::DOWN, Direction::LEFT, Direction::RIGHT}}};
            default:
                return {{}};
        }
    }

    static int size() {
        int i = 0;
        int value = static_cast<Areas>(0);
        while (value != end_value) {
            value = static_cast<Areas>(++i);
        }
        return i;
    }
};

#endif //AREAS_HPP