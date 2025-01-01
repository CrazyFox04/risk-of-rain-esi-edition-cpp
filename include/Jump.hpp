//
// Created by Enzo Renard on 26/12/2024.
//
/**
 * @file Jump.hpp
 * @brief Defines the Jump class, representing a character's ability to perform multiple jumps.
 *
 * The Jump class is a specialized type of Movement that allows a character to perform
 * consecutive jumps (e.g., double jumps, triple jumps) up to a defined limit. The usage
 * counter resets when the character touches the ground, allowing jumps to be performed again.
 */

#ifndef JUMP_HPP
#define JUMP_HPP
#include "Movement.hpp"

/**
 * @class Jump
 * @brief Represents a jumping movement with support for multiple consecutive jumps.
 *
 * The Jump class extends the Movement class and enforces a maximum number of consecutive jumps
 * allowed before requiring the character to touch the ground to reset the jump counter.
 */
class Jump : public Movement {
    int maxUsage; ///< Maximum number of consecutive jumps allowed.
    int currentUsage; ///< Current number of jumps performed since the last reset.

public:
    /**
     * @brief Constructs a Jump object with specified force and jump limits.
     * @param force The force applied during each jump.
     * @param maxUsage The maximum number of consecutive jumps allowed.
     */
    Jump(double force, int maxUsage);

    /**
     * @brief Checks if the character can perform a jump.
     * @return True if jumps are allowed, otherwise false.
     */
    [[nodiscard]] bool canUse() const override;

    /**
     * @brief Executes a jump, incrementing the current jump counter.
     * @throws std::runtime_error If the jump cannot be performed due to reaching the maximum limit.
     */
    void use() override;

    /**
     * @brief Resets the jump counter, typically called when the character touches the ground.
     */
    void reset();

    void increaseForce(double amount) override;
};
#endif //JUMP_HPP
