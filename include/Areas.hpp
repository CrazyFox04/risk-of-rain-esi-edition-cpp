//
// Created by Enzo Renard on 22/11/2024.
//

#ifndef AREAS_HPP
#define AREAS_HPP
#include "AreaType.hpp"
#include "Area.hpp"

enum class Areas {
    BIOME1
};

struct DefinedAreas {
    Area area;

    static DefinedAreas get(Areas areas) {
        switch (areas) {
            case Areas::BIOME1:
                return {{{{}}, {1}, UNDERWATER}};
            default:
                return {{{{}}, {1}, UNDERWATER}};
        }
    }
};

#endif //AREAS_HPP
