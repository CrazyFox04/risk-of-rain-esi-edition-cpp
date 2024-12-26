//
// Created by Enzo Renard on 26/12/2024.
//

#ifndef ATTACKS_HPP
#define ATTACKS_HPP
#include <magic_enum/magic_enum.hpp>

#include "Attack.hpp"

enum Attacks {
    ATTACK1,
    ATTACK2,
    ATTACK3,
    ATTACK4,
    ATTACK5,
    ATTACK_SPECTRUM,
    ATTACK_MONSTER,
    ATTACK_DROID
};

struct DefinedAttacks {
    Attack attack;

    static DefinedAttacks get(const Attacks attack) {
        switch (attack) {
            case ATTACK1:
                return DefinedAttacks{Attack("Attack1", 10, 0.42, 0.0, 0.42)};
            case ATTACK2:
                return DefinedAttacks{Attack("Attack2", 20, 1.5, 0.0, 0.4)};
            case ATTACK3:
                return DefinedAttacks{Attack("Attack3", 30, 5.0, 0.0, 1.0)};
            case ATTACK4:
                return DefinedAttacks{Attack("Attack4", 40, 2.0, 0.0, 1.0)};
            case ATTACK5:
                return DefinedAttacks{Attack("Attack5", 50, 5.0, 0.0, 1.0)};
            case ATTACK_SPECTRUM:
                return DefinedAttacks{Attack("AttackSpectrum", 75, 2.5, 1.0, 2.1)};
            case ATTACK_MONSTER:
                return DefinedAttacks{Attack("AttackMonster", 25, 1.0, 0.3, 0.8)};
            case ATTACK_DROID:
                return DefinedAttacks{Attack("AttackDroid", 50, 1.5, 1.0, 1.0)};
        }
    }

    static int size() {
        return magic_enum::enum_count<Attacks>();
    }
};
#endif //ATTACKS_HPP
