//
// Created by Enzo Renard on 13/12/2024.
//

#ifndef DIRECTION_HPP
#define DIRECTION_HPP

#include <utility>

/**
 * @brief Alias for a 2D direction representation.
 *
 * Direction2D is defined as a pair of integers, representing 2D movement
 * with the first element as the x-component and the second as the y-component.
 */
using Direction2D = std::pair<int, int>;

/**
 * @struct Direction
 * @brief Struct for defining common directions in a 2D space.
 *
 * The struct provides static constant directions as 2D vectors. These are commonly used
 * directions in a 2D grid, such as in games or graphical applications.
 */
struct Direction {
    static const Direction2D RIGHT; ///< Direction vector representing movement to the right.
    static const Direction2D DOWN; ///< Direction vector representing downward movement.
    static const Direction2D LEFT; ///< Direction vector representing movement to the left.
    static const Direction2D UP; ///< Direction vector representing upward movement.

    /**
     * @brief Gets the opposite direction of the given direction.
     * @param direction The direction to get the opposite of.
     * @return The opposite direction of the given direction.
     */
    static Direction2D getOppositeDirection(const Direction2D&direction);
};
#endif //DIRECTION_HPP
