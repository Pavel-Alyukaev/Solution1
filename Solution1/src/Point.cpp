#include <format>

std::string Point::toString() const {
    return std::format("{} {} {}", x, y, z);
}