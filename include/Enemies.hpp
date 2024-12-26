//
// Created by Enzo Renard on 26/12/2024.
//

#ifndef ENEMIES_HPP
#define ENEMIES_HPP
#include <Jump.hpp>
#include <Run.hpp>

#include "Enemy.hpp"

enum Enemies {
    SPECTRUM,
    SMALL_MONSTER,
    SHIELD_DROID
};

struct DefinedEnemies {
    Enemy enemy;

    static DefinedEnemies get(const Enemies enemies) {
        switch (enemies) {
            case SPECTRUM:
                std::set<std::shared_ptr<Movement>> movements{std::make_shared<Run>(1), std::make_shared<Jump>(5.0, 1)};
                return DefinedEnemies{
                    {
                        150, 15.0, 2.0, 0.5,
                        {
                            {DefinedAttacks::get(ATTACK_SPECTRUM).attack}, {
                                std::make_shared<Run>(1.5), std::make_shared<Jump>(5.0, 1)
                            },
                            false
                        },
                        false
                    }
                };
            case SMALL_MONSTER:
                return DefinedEnemies{
                    {
                        75, 10.0, 3.0, 0.5, {
                            {DefinedAttacks::get(ATTACK_SPECTRUM).attack}, {
                                std::make_shared<Run>(3), std::make_shared<Jump>(5.0, 1)
                            },
                            false
                        },
                        false
                    }
                };
            case SHIELD_DROID:
                return DefinedEnemies{
                    {
                        750, 15, 3.5, 0.5, {
                            {DefinedAttacks::get(ATTACK_DROID).attack},
                            {
                                std::make_shared<Run>(2), std::make_shared<Jump>(5.0, 1)
                            },
                            false
                        },
                        true
                    }
                };
        }
    }

    static int size() {
        return magic_enum::enum_count<Enemies>();
    }

    static std::set<Enemies> getAllEnemies() {
        std::set<Enemies> allEnemies;
        for (const auto&enemy: magic_enum::enum_values<Enemies>()) {
            if (enemy)
                allEnemies.insert(enemy);
        }
        return allEnemies;
    }
};
#endif //ENEMIES_HPP
