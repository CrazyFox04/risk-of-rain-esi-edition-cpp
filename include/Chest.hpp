//
// Created by Enzo Renard on 29/12/2024.
//

#ifndef CHEST_HPP
#define CHEST_HPP
#include "Item.hpp"

class Chest {
    int id;
    Item item;
    bool empty;

public:
    Chest(int id);

    bool isEmpty() const;

    Item open();

    int getId();

    static Item generate();
};
#endif //CHEST_HPP
