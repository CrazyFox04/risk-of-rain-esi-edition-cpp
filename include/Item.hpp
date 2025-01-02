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
    double probability; ///< The probability of the item being generated.

public:
    /**
     * @brief Constructs an Item object with specified parameters.
     * @param name The name of the item.
     * @param effect The effect value of the item.
     * @param effectDuration The duration of the item's effect.
     */
    Item(std::string name, double effect, double probability);

    /**
     * @brief Executes the item's effect and returns the effect value.
     * @throws std::runtime_error If the item cannot be used.
     * @return The effect value of the item.
     */
    double use() const;

    /**
     * @brief Retrieves the name of the item.
     * @return The name of the item.
     */
    [[nodiscard]] std::string getName() const;

    /**
     * @brief Retrieves the probability of the item being generated.
     * @return The Probability.
     */
    double getProbability() const;

    /**
     * @brief Custom comparison operator for Item objects.
     * @param other The other Item object to compare.
     */
    bool operator<(const Item& other) const {
        return name < other.name;
    }
};
#endif //RISK_OF_RAIN_ITEM_H
