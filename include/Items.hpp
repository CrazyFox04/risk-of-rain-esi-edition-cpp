//
// Created by Julien Delcombel on 24/11/2024.
//

#ifndef FLOOD_IT_CHARACTERMODIFIER_H
#define FLOOD_IT_CHARACTERMODIFIER_H
#include "magic_enum/magic_enum.hpp"
#include "Item.hpp"
#include <set>

enum Items {
    HEALTH_POTION, ///< Increases the character's health.
    HEALTH_BOOST, ///< Increases the character's maximum health.
    SPEED_BOOST, ///< Increases the character's movement speed.
    DAMAGE_BOOST, ///< Increases the character's attack damage.
    EXTRA_JUMP, ///< Grants the character an additional jump.
    TEDDY_BEAR, ///< Grants the character a teddy bear.
};

struct DefinedItems {
    Item item;

    /**
     * @brief Retrieves a predefined Buff object based on the specified Buff enum.
     * @param buff The Buff enum value representing the desired configuration.
     * @return A DefinedBuff object containing the corresponding Buff.
     */
    static DefinedItems get(const Items buff) {
        switch (buff) {
            case HEALTH_POTION:
                return DefinedItems{Item(getItemName(HEALTH_POTION), 50.0, 1)};
            case HEALTH_BOOST:
                return DefinedItems{Item(getItemName(HEALTH_BOOST), 20.0, 0.5)};
            case SPEED_BOOST:
                return DefinedItems{Item(getItemName(SPEED_BOOST), 4.0, 0.3)};
            case DAMAGE_BOOST:
                return DefinedItems{Item(getItemName(DAMAGE_BOOST), 15.0, 0.5)};
            case EXTRA_JUMP:
                return DefinedItems{Item(getItemName(EXTRA_JUMP), 1.0, 0.3)};
            case TEDDY_BEAR:
                return DefinedItems{Item(getItemName(TEDDY_BEAR), 0.0, 0.1)};
        }
    }

    /**
     * @brief Retrieves all predefined Item objects.
     * @return A set of all predefined Item objects.
     */
    static std::set<Item> getAllItems() {
        std::set<Item> items;
        for (auto buff : magic_enum::enum_values<Items>()) {
            items.insert(get(buff).item);
        }
        return items;
    }

    /**
     * @brief Retrieves the name of a specific item.
     * @param items The items enum.
     * @return The name of the item.
     */
    static std::string getItemName(Items items) {
        if (items < 0 || items >= size()) {
            throw std::out_of_range("Invalid buff enum value.");
        }
        return magic_enum::enum_name(static_cast<Items>(items)).data();
    }

    /**
     * @brief Retrieves the names of all predefined character items.
     * @return A set of strings representing the names of all character items.
     */
    static std::set<std::string> getCharacterBuffsName() {
        std::set<std::string> buffNames;
        for (auto buff : magic_enum::enum_values<Items>()) {
            buffNames.insert(std::string(magic_enum::enum_name(buff)));
        }
        return buffNames;
    }

    /**
     * @brief Checks if a given item name is valid.
     * @param buffName The name of the item.
     * @return True if the item name is valid, otherwise false.
     */
    static bool isValidBuffName(const std::string& buffName) {
        return getCharacterBuffsName().contains(buffName);
    }

    /**
     * @brief Gets the Enum size
     * @return The size of the enum.
     */
    static int size() {
        return magic_enum::enum_count<Items>();
    }

    /**
     * @brief Gets the ID of a specific item.
     * @param string The name of the item.
     * @return The ID of the item, or -1 if the item does not exist.
     */
    static int getId(const std::string& string) {
        for (int i = 0; i < size(); ++i) {
            if (getItemName(static_cast<Items>(i)) == string) {
                return i;
            }
        }
        return -1;
    }
};


#endif //FLOOD_IT_CHARACTERMODIFIER_H
