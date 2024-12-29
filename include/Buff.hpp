//
// Created by Julien Delcombel on 24/11/2024.
//

#ifndef FLOOD_IT_CHARACTERMODIFIER_H
#define FLOOD_IT_CHARACTERMODIFIER_H
#include "magic_enum/magic_enum.hpp"
#include "Item.hpp"

enum class Buff {
    HEALTH_POTION, ///< Increases the character's health.
    HEALTH_BOOST, ///< Increases the character's maximum health.
    SPEED_BOOST, ///< Increases the character's movement speed.
    DAMAGE_BOOST, ///< Increases the character's attack damage.
    COOLDOWN_REDUCTION, ///< Reduces the cooldown time for attacks.
    EXTRA_JUMP, ///< Grants the character an additional jump.
    JETPACK_REFILL ///< Refills the character's jetpack fuel.
};

struct DefinedBuff {
    Item item;

    /**
     * @brief Retrieves a predefined Buff object based on the specified Buff enum.
     * @param buff The Buff enum value representing the desired configuration.
     * @return A DefinedBuff object containing the corresponding Buff.
     */
    static DefinedBuff get(const Buff buff) {
        switch (buff) {
            case Buff::HEALTH_POTION:
                return DefinedBuff{Item("HEALTH_POTION", 50.0, 0.0)};
            case Buff::HEALTH_BOOST:
                return DefinedBuff{Item("HEALTH_BOOST", 20.0, 0.0)};
            case Buff::SPEED_BOOST:
                return DefinedBuff{Item("SPEED_BOOST", 4.0, 30.0)};
            case Buff::DAMAGE_BOOST:
                return DefinedBuff{Item("DAMAGE_BOOST", 15.0, 30.0)};
            case Buff::COOLDOWN_REDUCTION:
                return DefinedBuff{Item("COOLDOWN_REDUCTION", -2.0, 30.0)};
            case Buff::EXTRA_JUMP:
                return DefinedBuff{Item("EXTRA_JUMP", 1.0, 0.0)};
            case Buff::JETPACK_REFILL:
                return DefinedBuff{Item("JETPACK_REFILL", 10.0, 0.0)};
        }
    }

    static std::set<Buff> getAllBuffs() {
        std::set<Buff> buffs;
        for (int i = 0; i < size(); ++i) {
            buffs.insert(get(static_cast<Buff>(i)).item);
        }
        return buffs;
    }

    static std::string getBuffName(int buff) {
        if (buff < 0 || buff >= size()) {
            throw std::out_of_range("Invalid buff enum value.");
        }
        return magic_enum::enum_name(static_cast<Buff>(buff)).data();
    }

    static std::set<std::string> getCharacterBuffsName() {
        auto buffs = getAllBuffs();
        std::set<std::string> buffNames;
        for (const auto& buff : buffs) {
            buffNames.insert(getBuffName(static_cast<int>(buff)));
        }
        return buffNames;
    }

    static bool isValidBuffName(const std::string& buffName) {
        return getCharacterBuffsName().contains(buffName);
    }

    static int size() {
        return magic_enum::enum_count<Buff>();
    }
};


#endif //FLOOD_IT_CHARACTERMODIFIER_H
