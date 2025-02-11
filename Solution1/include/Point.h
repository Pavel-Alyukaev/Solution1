#pragma once
#include <string>

struct Point
{
    double x, y, z;

    [[nodiscard]] std::string toString() const;
};

