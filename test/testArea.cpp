//
// Created by Enzo Renard on 24/12/2024.
//
#include <Areas.hpp>
#include <gtest/gtest.h>
#include "Area.hpp"
#include "Direction.hpp"

TEST(AreaTest, DefaultConstructorInitializesWithNegativeOneType) {
    Area area;
    EXPECT_EQ(area.get_type(), -1);
}

TEST(AreaTest, ParameterizedConstructorInitializesCorrectly) {
    std::set<Direction2D> gateways = {Direction::UP, Direction::DOWN};
    Area area(1, 10, gateways, {});
    EXPECT_EQ(area.get_type(), 1);
    EXPECT_EQ(area.get_id(), area.get_id()); // Ensure ID is within range
    EXPECT_TRUE(area.get_gateway_positions().contains(Direction::UP));
    EXPECT_TRUE(area.get_gateway_positions().contains(Direction::DOWN));
}

TEST(AreaTest, GetRandomAreaReturnsValidArea) {
    Area area = Area::getRandomArea();
    EXPECT_GE(area.get_type(), 0);
    EXPECT_LE(area.get_type(), DefinedAreas::size());
}

TEST(AreaTest, IsCompatibleReturnsTrueForUnchosenArea) {
    Area area1(1, 10, {Direction::UP});
    Area area2;
    EXPECT_TRUE(area1.isCompatible(Direction::UP, area2));
}

TEST(AreaTest, IsCompatibleReturnsTrueForTypeZeroWithoutGateway) {
    Area area1(1, 10, {Direction::UP});
    Area area2(0, 10, {});
    EXPECT_TRUE(area1.isCompatible(Direction::DOWN, area2));
    EXPECT_TRUE(area1.isCompatible(Direction::LEFT, area2));
    EXPECT_TRUE(area1.isCompatible(Direction::RIGHT, area2));
}

TEST(AreaTest, IsCompatibleReturnsTrueForMatchingGateways) {
    Area area1(1, 10, {Direction::UP});
    Area area2(1, 10, {Direction::DOWN});
    EXPECT_TRUE(area1.isCompatible(Direction::UP, area2));
}

TEST(AreaTest, IsCompatibleReturnsFalseForNonMatchingGateways) {
    Area area1(1, 10, {Direction::UP});
    Area area2(1, 10, {Direction::LEFT});
    EXPECT_FALSE(area1.isCompatible(Direction::UP, area2));
}
