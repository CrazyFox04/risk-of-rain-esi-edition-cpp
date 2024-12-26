//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <chrono>
#include <string>
#include <set>
#include <array>
#include "Dash.hpp"
#include "Jump.hpp"
#include "Run.hpp"

#include "Capabilities.hpp"
#include "Health.hpp"
#include "Character.hpp"

class Player : public Character {
public:
    static constexpr int DEF_MAX_HEALTH = 100;
    static constexpr double DEF_RUN_FORCE = 4.0;
    static constexpr double DEF_JUMP_FORCE = 5.0;
    static constexpr double DEF_HURT_TIME = 0.5;
    static const std::set<std::shared_ptr<Movement>> DEF_MOVEMENTS_PLAYER;
    static const std::set<Attack> DEF_ATTACKS_PLAYER;

    Player();

    ~Player() override = default;

    void addItem(std::shared_ptr<Buff> item) override;
};

#endif //PLAYER_HPP
