//
// Created by Julien Delcombel on 24/11/2024.
//

#ifndef FLOOD_IT_ITEM_H
#define FLOOD_IT_ITEM_H

#include <string>


class Item {
public:
    virtual ~Item() {}

    virtual std::string getName() const = 0;
    virtual void
};

#endif //FLOOD_IT_ITEM_H
