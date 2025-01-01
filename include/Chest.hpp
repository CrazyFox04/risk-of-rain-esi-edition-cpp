//
// Created by Enzo Renard on 29/12/2024.
//
/**
 * @file Chest.hpp
 * @brief Defines the Chest class, representing a chest with an item that can be opened.
 *
 * The Chest class encapsulates the attributes and functionalities of a chest object.
 */
#ifndef CHEST_HPP
#define CHEST_HPP
#include "Item.hpp"

/**
 * @class Chest
 * @brief Represents a chest object that can be opened to reveal an item.
 */
class Chest {
    int id; ///< The unique identifier of the chest.
    Item item; ///< The item contained in the chest.
    bool empty; ///< Indicates whether the chest is empty.

public:
    /**
     * @brief Constructs a Chest object with a specified ID.
     * @param id The unique identifier of the chest.
     */
    Chest(int id);

    /**
     * @brief Checks if the chest is empty.
     * @return True if the chest is empty, otherwise false.
     */
    bool isEmpty() const;

    /**
     * @brief Opens the chest making it empty and retrieves the item inside.
     * @return The item contained in the chest.
     */
    Item open();

    /**
     * @brief Gets the unique identifier of the chest.
     * @return The ID of the chest.
     */
    int getId();

    /**
     * @brief Generates a random item to be placed in the chest.
     * @return The randomly generated item.
     */
    static Item generate();
};
#endif //CHEST_HPP
