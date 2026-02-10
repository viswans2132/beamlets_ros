#include "config.h"

const std::vector<std::vector<int>> Config::grid = {
    {0, 0, 0, 0, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 1, 1},
    {1, 1, 0, 0, 1, 1, 1, 1},
    {1, 1, 0, 0, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0},
};

const int Config::smax = 3;
const double Config::alpha = 0.0;