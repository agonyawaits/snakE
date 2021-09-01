#pragma once
#include <ncurses.h>
#include "idrawable.h"
#include "v2.h"

#define ENTER 10

struct Menu : public IDrawable {
    Menu(const V2 &text_position)
        : m_textpos(text_position), m_highlight(0), m_borders(true), m_active(true)
    {
    }

    void draw(WINDOW *window) const override
    {
        for(int mi = PLAY; mi < NUM_CHOICES; ++mi)
        {
            if(mi == m_highlight)
                wattron(window, A_REVERSE);
            mvwprintw(window, m_textpos.y+mi, m_textpos.x, "%s%s", m_items[mi],
                mi == BORDERS ? (m_borders ? " ON" : " OFF") : "");
            wattroff(window, A_REVERSE);
        }

    }

    void update(int key)
    {
        switch(key)
        {
            case KEY_UP:
            {
                if(m_highlight > PLAY)
                    --m_highlight;
            } break;
            case KEY_DOWN:
            {
                if(m_highlight < QUIT)
                    ++m_highlight;
            } break;
            case ENTER:
            {
                if(m_highlight == BORDERS)
                    m_borders = !m_borders;
                else
                    m_active = false;
            } break;
        }
    }

    bool borders_on() const
    {
        return m_borders;
    }

    bool active() const
    {
        return m_active;
    }

private:
    const char *m_items[3] = {"Play", "Borders:", "Quit"};
    enum MenuItem {
        PLAY,
        BORDERS,
        QUIT,
        NUM_CHOICES
    };

private:
    V2      m_textpos;
    int     m_highlight;
    bool    m_borders;
    bool    m_active;
};
