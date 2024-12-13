//
// Created by Enzo Renard on 28/11/2024.
//
#include <Game.hpp>
#include <gtest/gtest.h>

int main(int a, char * av[]) {
    testing::InitGoogleTest(&a, av);
    return RUN_ALL_TESTS();
}

TEST(Game, getActiveLevel) {
    auto game = Game();
    ASSERT_EQ(0, game.getActiveLevel().getId());
}
