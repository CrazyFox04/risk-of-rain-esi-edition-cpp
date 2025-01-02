//
// Created by Julien Delcombel on 29/12/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Item.hpp"

#include <utility>

Item::Item(std::string name, const double effect, const double probability) : name(std::move(name)), effect(effect), probability(probability) {
}

double Item::use() const {
    return effect;
}

std::string Item::getName() const {
    return name;
}

double Item::getProbability() const {
    return probability;
}