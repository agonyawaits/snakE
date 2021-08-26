#pragma once

#include <ncurses.h>

struct IDrawable {
    virtual ~IDrawable() = default;
    virtual void draw(WINDOW *) const = 0;
};
