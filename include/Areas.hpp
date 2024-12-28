// include/Areas.hpp
/**
 * @file Areas.hpp
 * @brief Defines the Areas enum and the DefinedAreas struct for managing predefined game regions.
 *
 * The Areas enum lists predefined area configurations, while the DefinedAreas struct provides
 * functionality to retrieve specific Area objects based on the enum values.
 */
#ifndef AREAS_HPP
#define AREAS_HPP
#include "Direction.hpp"
#include "Area.hpp"
#include "magic_enum/magic_enum.hpp"

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
    A4URDL
};

/**
 * @struct DefinedAreas
 * @brief Provides functionality to retrieve predefined Area objects.
 */
struct DefinedAreas {
    Area area;

    /**
     * @brief Retrieves a predefined Area object based on the specified Areas enum.
     * @param areas The Areas enum value representing the desired configuration.
     * @return A DefinedAreas object containing the corresponding Area.
     */
    static DefinedAreas get(const Areas areas) {
        switch (areas) {
            case A1U:
                return DefinedAreas{Area(11, 1, {Direction::UP}, {{1, 10000, 100000}})};
            case A1R:
                return DefinedAreas{Area(12, 1, {Direction::RIGHT}, {{1, 10000, 100000}})};
            case A1D:
                return DefinedAreas{Area(13, 1, {Direction::DOWN}, {{1, 10000, 100000}})};
            case A1L:
                return DefinedAreas{Area(14, 1, {Direction::LEFT}, {{1, 10000, 100000}})};
            case A2UR:
                return DefinedAreas{Area(21, 1, {Direction::UP, Direction::RIGHT}, {{1, 10000, 100000}})};
            case A2LD:
                return DefinedAreas{Area(22, 1, {Direction::LEFT, Direction::DOWN}, {{1, 10000, 100000}})};
            case A2UL:
                return DefinedAreas{Area(23, 1, {Direction::UP, Direction::LEFT}, {{1, 1, 10}})};
            case A2DR:
                return DefinedAreas{Area(24, 1, {Direction::DOWN, Direction::RIGHT}, {{1, 1, 10}})};
            case A2UD:
                return DefinedAreas{Area(25, 1, {Direction::UP, Direction::DOWN}, {{1, 1, 10}})};
            case A2LR:
                return DefinedAreas{Area(26, 1, {Direction::LEFT, Direction::RIGHT}, {{1, 1, 10}})};
            case A3LUR:
                return DefinedAreas{Area(31, 1, {Direction::UP, Direction::LEFT, Direction::RIGHT}, {{1, 1, 10}})};
            case A3URD:
                return DefinedAreas{Area(32, 1, {Direction::UP, Direction::RIGHT, Direction::DOWN}, {{1, 1, 10}})};
            case A3LDR:
                return DefinedAreas{Area(33, 1, {Direction::LEFT, Direction::DOWN, Direction::RIGHT}, {{1, 1, 10}})};
            case A3ULD:
                return DefinedAreas{Area(34, 1, {Direction::UP, Direction::LEFT, Direction::DOWN}, {{1, 1, 10}})};
            case A4URDL:
                return DefinedAreas{Area(40, 2, {Direction::UP, Direction::RIGHT, Direction::DOWN, Direction::LEFT}, {{1, 1, 10}})};
        }
    }

    /**
     * @brief Retrieves the number of predefined Areas.
     * @return The number of elements in the Areas enum.
     */
    static int size() {
        return magic_enum::enum_count<Areas>();
    }
};

#endif //AREAS_HPP
