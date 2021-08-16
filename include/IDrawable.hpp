#pragma once

#include <ncurses.h>

class IDrawable {
public:
    virtual ~IDrawable() = default;
    virtual void draw(WINDOW*) const = 0;
};
