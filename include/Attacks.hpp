//
// Created by Enzo Renard on 26/12/2024.
//
/**
 * @file Attacks.hpp
 * @brief Defines the Attacks enum and the DefinedAttacks struct for managing predefined attacks.
 *
 * The Attacks enum lists predefined attack configurations, while the DefinedAttacks struct provides
 * functionality to retrieve specific Attack objects and perform operations on them.
 */
#ifndef ATTACKS_HPP
#define ATTACKS_HPP
#include "magic_enum/magic_enum.hpp"

#include "Attack.hpp"

/**
 * @enum Attacks
 * @brief Represents predefined attack configurations.
 */
enum Attacks {
    ATTACK1,          ///< Basic attack with low damage and short cooldown.
    ATTACK2,          ///< Medium damage attack with a moderate cooldown.
    ATTACK3,          ///< High damage attack with a long cooldown.
    ATTACK4,          ///< Strong attack with a balanced cooldown.
    ATTACK5,          ///< Very high damage attack with a long cooldown.
    ATTACK_SPECTRUM,  ///< A special spectrum attack with unique properties.
    ATTACK_MONSTER,   ///< Monster-themed attack with moderate damage and cooldown.
    ATTACK_DROID      ///< Droid-specific attack with high damage and a short charge time.
};

/**
 * @struct DefinedAttacks
 * @brief Provides functionality to retrieve predefined Attack objects and perform operations on them.
 */
struct DefinedAttacks {
    Attack attack;

    /**
     * @brief Retrieves a predefined Attack object based on the specified Attacks enum.
     * @param attack The Attacks enum value representing the desired configuration.
     * @return A DefinedAttacks object containing the corresponding Attack.
     */
    static DefinedAttacks get(const Attacks attack) {
        switch (attack) {
            case ATTACK1:
                return DefinedAttacks{Attack("ATTACK1", 20, 0.42, 0.05, 0.42)};
            case ATTACK2:
                return DefinedAttacks{Attack("ATTACK2", 50, 0.75, 0.2, 0.4)};
            case ATTACK3:
                return DefinedAttacks{Attack("ATTACK3", 100, 5.0, 0.4, 1.0)};
            case ATTACK4:
                return DefinedAttacks{Attack("ATTACK4", 80, 2.0, 0.3, 0.6)};
            case ATTACK5:
                return DefinedAttacks{Attack("ATTACK5", 160, 5.0, 0.6, 1.5)};
            case ATTACK_SPECTRUM:
                return DefinedAttacks{Attack("ATTACK_SPECTRUM", 75, 4.0, 1.0, 2.1)};
            case ATTACK_MONSTER:
                return DefinedAttacks{Attack("ATTACK_MONSTER", 25, 1.0, 0.3, 0.8)};
            case ATTACK_DROID:
                return DefinedAttacks{Attack("ATTACK_DROID", 50, 1.5, 0.2, 1.0)};
        }
    }

    /**
     * @brief Retrieves all predefined Attack objects.
     * @return A set of all predefined Attack objects.
     */
    static std::set<Attack> getAllAttacks() {
        std::set<Attack> attacks;
        for (int i = 0; i < size(); ++i) {
            attacks.insert(get(static_cast<Attacks>(i)).attack);
        }
        return attacks;
    }

    /**
     * @brief Retrieves the name of a specific attack.
     * @param attack The attack enum value.
     * @return The name of the attack.
     */
    static std::string getAttackName(int attack) {
        if (attack < 0 || attack >= size()) {
            throw std::out_of_range("Invalid attack enum value.");
        }
        return magic_enum::enum_name(static_cast<Attacks>(attack)).data();
    }

    /**
     * @brief Retrieves the names of all predefined character attacks.
     * @return A set of strings representing the names of all character attacks.
     */
    static std::set<std::string> getCharacterAttacksName() {
        auto attacks = getAllAttacks();
        auto names = std::set<std::string>();
        for (const auto&attack: attacks) {
            names.insert(attack.getName());
        }
        return names;
    }

    /**
     * @brief Checks if a given attack name is valid.
     * @param attackName The name of the attack to validate.
     * @return True if the attack name is valid, otherwise false.
     */
    static bool isAValidAttackName(const std::string&attackName) {
        return getCharacterAttacksName().contains(attackName);
    }

    static int getAttackValue(const std::string&attackName) {
        for (int i = 0; i < size(); ++i) {
            if (get(static_cast<Attacks>(i)).attack.getName() == attackName) {
                return i;
            }
        }
        throw std::invalid_argument("Invalid attack name");
    }
    
    /**
     * @brief Retrieves the number of predefined Attacks.
     * @return The number of elements in the Attacks enum.
     */
    static int size() {
        return magic_enum::enum_count<Attacks>();
    }
};
#endif //ATTACKS_HPP
