#pragma once

#include "Direction.hpp"

class Input final {
public:
    Input(const int&);

    Direction direction() const;

private:
    int m_input;
};
