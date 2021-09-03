#pragma once
#include <ncurses.h>
#include <cstring>
#include "idrawable.h"
#include "v2.h"

#define ENTER 10

struct Menu : public IDrawable {
    Menu(const V2 &window_size);

    void draw(WINDOW *window) const override;
    void update(int key);
    bool borders_on() const;
    bool active() const;
    bool quited() const;
    void reset();

private:
    enum MenuItem {
        PLAY,
        BORDERS,
        QUIT,
        NUM_CHOICES
    };

    const char *m_items[NUM_CHOICES] = {"Play", "Borders:", "Quit"};
    V2          m_wsize;
    int         m_selection;
    bool        m_borders;
    bool        m_active;
};
