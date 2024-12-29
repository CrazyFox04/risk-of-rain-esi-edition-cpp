//
// Created by Julien Delcombel on 29/12/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Item.hpp"

Item::Item(const std::string&name, double effect, double probability) : name(name), effect(effect), probability(probability) {
}

double Item::use() {
    return effect;
}

std::string Item::getName() const {
    return name;
}

double Item::getProbability() const {
    return probability;
}