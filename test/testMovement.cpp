//
// Created by Enzo Renard on 27/12/2024.
//
#include <Movement.hpp>
#include <gtest/gtest.h>

TEST(MovementTest, canUsemovement) {
    Movement movement = Movement("RUN", 1, 1, 1);
    EXPECT_TRUE(movement.canUse());
    EXPECT_NO_THROW(movement.use());
    EXPECT_TRUE(movement.isUsing());
    sleep(3);
    EXPECT_TRUE(movement.canUse());
    EXPECT_NO_THROW(movement.use());
    EXPECT_TRUE(movement.isUsing()); 
    EXPECT_FALSE(movement.canUse());
    EXPECT_TRUE(movement.isUsing());
}