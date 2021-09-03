#pragma once

#include <ncurses.h>
#include "v2.h"
#include "idrawable.h"
#include "entity.h"

enum Color {
    GREEN = 1, RED, YELLOW
};

struct Input {
    Input(int);
    Direction direction() const;
    int key() const;

private:
    int m_input;
};

struct Window {
    Window();
    ~Window();

    void    clear() const;
    void    render(const IDrawable &) const;
    void    render(const IDrawable &, Color) const;
    Input   input() const;
    V2      size() const;
    
private:
    V2      m_size;
    WINDOW *m_window;
};
