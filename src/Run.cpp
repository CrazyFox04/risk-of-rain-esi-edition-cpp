//
// Created by Enzo Renard on 26/12/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "Run.hpp"

Run::Run(double force) : Movement("RUN", force, 0, 0) {
}
