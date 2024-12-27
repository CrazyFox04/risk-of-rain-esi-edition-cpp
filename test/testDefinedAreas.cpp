//
// Created by Enzo Renard on 24/12/2024.
//

#include "Areas.hpp"
#include <gtest/gtest.h>

TEST(DefinedAreasTest, GetReturnsCorrectArea) {
    DefinedAreas definedArea = DefinedAreas::get(A2UD);
    EXPECT_EQ(definedArea.area.get_id(), 1);
    EXPECT_TRUE(definedArea.area.get_gateway_positions().contains(Direction::DOWN));
    EXPECT_TRUE(definedArea.area.get_gateway_positions().contains(Direction::UP));
}
