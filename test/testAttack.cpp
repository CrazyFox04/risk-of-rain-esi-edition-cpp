//
// Created by Enzo Renard on 27/12/2024.
//
#include <gtest/gtest.h>
#include "Attack.hpp"

TEST(AttackTest, canUseAttack) {
    Attack attack = Attack("ATTACK1", 10, 1, 1, 1);
    EXPECT_TRUE(attack.canUse());
    EXPECT_NO_THROW(attack.use());
    EXPECT_TRUE(attack.isUsing());
    sleep(3);
    EXPECT_TRUE(attack.canUse());
    EXPECT_NO_THROW(attack.use());
    EXPECT_TRUE(attack.isUsing()); 
    EXPECT_FALSE(attack.canUse());
    EXPECT_TRUE(attack.isUsing());
}