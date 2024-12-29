//
// Created by Julien Delcombel on 29/12/2024.
//
/**
 * @file Item.hpp
 * @brief Defines the Item class, representing a generic item in the game.
 *
 * The Item class serves as a base class for different types of items. It includes
 * properties for effect, effect duration, and last usage time, and provides methods
 * to use the item, check availability, and retrieve item details.
 */
#ifndef RISK_OF_RAIN_ITEM_H
#define RISK_OF_RAIN_ITEM_H
#include <string>
#include <chrono>

/**
 * @class Item
 * @brief Represents a generic item in the game.
 *
 * The Item class manages the logic for item effects, duration, and usage.
 */
class Item {
    std::string name; ///< The name of the item.
    double effect; ///< The effect value of the item.
    double effectDuration; ///< The duration of the item's effect.
    std::chrono::time_point<std::chrono::steady_clock> lastUsageTime; ///< The last time the item was used.

public:
    /**
     * @brief Constructs an Item object with specified parameters.
     * @param name The name of the item.
     * @param effect The effect value of the item.
     * @param effectDuration The duration of the item's effect.
     */
    Item(const std::string&name, double effect, double effectDuration);

    /**
     * @brief Executes the item's effect and returns the effect value.
     * @throws std::runtime_error If the item cannot be used.
     * @return The effect value of the item.
     */
    double use();

    /**
     * @brief Checks if the item is currently in effect.
     * @return True if the item is effective, otherwise false.
     */
    [[nodiscard]] bool isUsing() const;

    /**
     * @brief Checks if the item can be used.
     * @return True if the item can be used, otherwise false.
     */
    [[nodiscard]] bool canUse() const;

    /**
     * @brief Retrieves the effect value of the item.
     * @return The effect value.
     */
    [[nodiscard]] double getEffect() const;

    /**
     * @brief Retrieves the duration of the item's effect.
     * @return The effect duration.
     */
    [[nodiscard]] double getEffectDuration() const;

    /**
     * @brief Retrieves the name of the item.
     * @return The name of the item.
     */
    [[nodiscard]] std::string getName() const;

    /**
     * @brief Retrieves the last time the item was used.
     * @return The time point of the last usage.
     */
    [[nodiscard]] std::chrono::time_point<std::chrono::steady_clock> getLastUsageTime() const;
};
#endif //RISK_OF_RAIN_ITEM_H
