//
// Created by Enzo Renard on 28/12/2024.
//
/**
 * @file Climb.hpp
 * @brief Climb class header file
 */
#ifndef CLIMB_HPP
#define CLIMB_HPP
#include "Movement.hpp"

/**
 * @class Climb
 * @brief Represents the climbing movement
 */
class Climb : public Movement {
    bool climbing = false; ///< Indicates whether the character is climbing
public:
    /**
     * @brief Constructs a Climb object with a specified force
     * @param force The force of the climbing movement
     */
    explicit Climb(double force);

    /**
     * @brief Uses the climbing movement
     * @throws std::invalid_argument if the movement is unavailable
     */
    void use() override;

    /**
     * @brief Changes the climbing status to false
     */
    void stop() override;

    /**
     * @brief Checks if the character is climbing
     * @return climbing status
     */
    bool isUsing() const override;

    /**
     * @brief Checks if the climbing movement is available
     * @note The climbing movement is always available in this game
     * @return true
     */
    bool canUse() const override;
};
#endif //CLIMB_HPP
