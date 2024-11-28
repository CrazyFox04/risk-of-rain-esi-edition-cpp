//
// Created by Enzo Renard on 22/11/2024.
//

#ifndef AREAS_HPP
#define AREAS_HPP
#include "AreaType.hpp"
#include "Area.hpp"
#define end_value 999999

enum Areas {
    BIOME1 = end_value
};

struct DefinedAreas {
    Area area;

    static DefinedAreas get(Areas areas) {
        switch (areas) {
            case BIOME1:
                return {{{{}}, {1}, UNDERWATER}};
            default:
                return {{{{}}, {1}, UNDERWATER}};
        }
    }

    static int size() {
        int i = 0;
        int value = static_cast<Areas>(0); 
        while (value != end_value) {
            value = static_cast<Areas>(++i);
        }
        return i;
    }
};

#endif //AREAS_HPP
