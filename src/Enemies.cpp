//
// Created by Enzo Renard on 26/12/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Enemies.hpp"
#include "Enemy.hpp"
#include "Run.hpp"
#include "Jump.hpp"
#include "Attacks.hpp"
#include <memory>

DefinedEnemies DefinedEnemies::get(const Enemies enemies) {
    switch (enemies) {
        case SPECTRUM: {
            std::set<std::shared_ptr<Movement>> movements{std::make_shared<Run>(1), std::make_shared<Jump>(5.0, 1)};
            return DefinedEnemies{
                {
                    "SPECTRUM",150, 15.0, 2.0, 0.5,
                    {
                        {DefinedAttacks::get(ATTACK_SPECTRUM).attack}, {
                            std::make_shared<Run>(1.5), std::make_shared<Jump>(5.0, 1)
                        },
                        false
                    },
                    false
                }
            };
            break;
        }
        case SMALL_MONSTER: {
            return DefinedEnemies{
                {
                    "SMALL_MONSTER",75, 10.0, 3.0, 0.5, {
                        {DefinedAttacks::get(ATTACK_SPECTRUM).attack}, {
                            std::make_shared<Run>(3), std::make_shared<Jump>(5.0, 1)
                        },
                        false
                    },
                    false
                }
            };
            break;
        }
        case SHIELD_DROID: {
            return DefinedEnemies{
                {
                    "SHIELD_DROID",750, 15, 3.5, 0.5, {
                        {DefinedAttacks::get(ATTACK_DROID).attack},
                        {
                            std::make_shared<Run>(2), std::make_shared<Jump>(5.0, 1)
                        },
                        false
                    },
                    true
                }
            };
            break;
        }
        default:
            throw std::invalid_argument("This enemy does not exist");
    }
}

int DefinedEnemies::size() {
    return magic_enum::enum_count<Enemies>();
}

std::unordered_set<Enemies> DefinedEnemies::getAllEnemies() {
    std::unordered_set<Enemies> allEnemies;
    for (const auto& enemy : magic_enum::enum_values<Enemies>()) {
        if (enemy)
            allEnemies.insert(enemy);
    }
    return allEnemies;
}