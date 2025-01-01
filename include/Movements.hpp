//
// Created by Enzo Renard on 28/12/2024.
//
/**
 * @enum Movements
 * @brief Enumerates the different movement types available in the game.
 *
 * This enumeration defines the various movement capabilities that a character
 * can perform, such as running, jumping, and using a jetpack.
 *
 * @see DefinedMovements
 */
#ifndef MOVEMENTS_HPP
#define MOVEMENTS_HPP
#include <set>
#include "magic_enum/magic_enum.hpp"

enum Movements {
    RUN, ///< Represents the ability to run.
    JUMP, ///< Represents the ability to jump.
    DASH, ///< Represents the ability to dash.
    JETPACK, ///< Represents the ability to use a jetpack.
    CLIMB ///< Represents the ability to climb.
};

/**
 * @struct DefinedMovements
 * @brief Provides utility functions for managing and retrieving movement-related data.
 *
 * This utility class offers methods to retrieve movement names, indices, and
 * validate movement names against the predefined `Movements` enum.
 *
 * @see Movements
 */
struct DefinedMovements {

    /**
     * @brief Retrieves the name of a movement by its index.
     *
     * Converts a movement index to its corresponding name as defined in the `Movements` enum.
     *
     * @param movementIndex The index of the movement in the `Movements` enum.
     * @return The name of the movement as a string.
     * @throws std::out_of_range If the index is invalid (less than 0 or greater than the enum size).
     */
    static std::string getMovementName(int movementIndex) {
        if (movementIndex < 0 || movementIndex >= size()) {
            throw std::out_of_range("Invalid movement enum value.");
        }
        return magic_enum::enum_name(static_cast<Movements>(movementIndex)).data();
    }

    /**
     * @brief Retrieves the total number of movements defined in the `Movements` enum.
     *
     * @return The total count of movements as an integer.
     */
    static int size() {
        return magic_enum::enum_count<Movements>();
    }

    /**
     * @brief Retrieves the movement enum value for a given movement type.
     *
     * @param movement The movement type to retrieve.
     * @return The movement enum value.
     */
    static Movements get(Movements movement) {
        return movement;
    }

    /**
     * @brief Retrieves all movement types defined in the `Movements` enum.
     *
     * @return A set containing all movement types as enum values.
     */
    static std::set<Movements> getAllMovements() {
        std::set<Movements> movements;
        for (int i = 0; i < size(); ++i) {
            movements.insert(get(static_cast<Movements>(i)));
        }
        return movements;
    }

    /**
     * @brief Retrieves the names of all character movements.
     *
     * This method converts all movement enum values into their corresponding string names.
     *
     * @return A set of movement names as strings.
     */
    static std::set<std::string> getCharacterMovementsName() {
        auto movements = getAllMovements();
        auto names = std::set<std::string>();
        for (const auto&movement: movements) {
            names.insert(getMovementName(movement));
        }
        return names;
    }

    /**
     * @brief Checks if a given movement name is valid.
     *
     * Verifies if the provided movement name exists in the list of predefined movements.
     *
     * @param move The movement name to validate.
     * @return True if the movement name is valid, otherwise false.
     */
    static bool isAValidMovementName(const std::string&move) {
        return getCharacterMovementsName().contains(move);
    }

    /**
     * @brief Retrieves the index of a movement by its name.
     *
     * Finds the index of a movement in the `Movements` enum based on its string name.
     *
     * @param movementName The name of the movement as a string.
     * @return The index of the movement, or -1 if the movement name is invalid.
     */
    static int getMovementIndex(const std::string& movementName) {
        for (int i = 0; i < size(); ++i) {
            if (getMovementName(i) == movementName) {
                return i;
            }
        }
        return -1;
    }
};
#endif //MOVEMENTS_HPP
