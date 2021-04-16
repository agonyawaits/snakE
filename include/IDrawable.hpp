#pragma once

#include <ncurses.h>

class IDrawable {
public:
    virtual void draw(WINDOW*) const = 0;
};
