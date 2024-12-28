//
// Created by Enzo Renard on 28/12/2024.
//
#include "gtest/gtest.h"
#include "GameController.hpp"

TEST(GameControllerTest, getAttackDamage) {
    GameController game_controller = GameController();
    int id = game_controller.getPlayerId();
    EXPECT_NO_THROW(game_controller.getCharacterAttackTime(id, 4));
    EXPECT_EQ(-1, game_controller.getCharacterAttackTime(id, 4));
}
