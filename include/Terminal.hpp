#pragma once

#include "Vector2.hpp"

class Terminal final {
public:
    Terminal(const Vector2i&);
    ~Terminal();

    void snake() const;

private:
    Vector2i m_size;
};
