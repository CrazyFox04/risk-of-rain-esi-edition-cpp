//
// Created by Enzo Renard on 29/12/2024.
//
#include "Chest.hpp"

#include "Items.hpp"
#include <random>
#include <vector>

Chest::Chest(int id) : id(id), item(generate()), empty(false) {
}

bool Chest::isEmpty() const {
    return empty;
}

Item Chest::open() {
    empty = true;
    return item;
}

Item Chest::generate() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<Item> items;
    for (int i = 0; i < DefinedItems::size(); ++i) {
        Item item = DefinedItems::get(static_cast<Items>(i)).item;
        std::uniform_int_distribution<> dis(0, 10);
        if (dis(gen) <= item.getProbability()*10) {
            items.emplace_back(item);
        }
    }
    std::uniform_int_distribution<> dis(0, items.size() - 1);
    return items[dis(gen)];
}

int Chest::getId() {
    return id;
}
