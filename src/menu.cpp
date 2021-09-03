#include "menu.h"

Menu::Menu(const V2 &window_size)
    : m_wsize(window_size), m_selection(0), m_borders(true), m_active(true)
{
}

void
Menu::draw(WINDOW *window) const {
    int sy = m_wsize.y/2 - NUM_CHOICES/2;
    for(int mi = PLAY; mi < NUM_CHOICES; ++mi)
    {
        int sx = m_wsize.x/2 - strlen(m_items[mi])/2;
        if(mi == m_selection)
        {
            mvwprintw(window, sy + mi, sx-2, "> ");
            wattron(window, A_REVERSE);
        }
        mvwprintw(window, sy+mi, sx, "%s%s", m_items[mi],
                mi == BORDERS ? (m_borders ? " ON" : " OFF") : "");
        wattroff(window, A_REVERSE);
    }
}

void
Menu::update(int key) {
    switch(key) {
        case KEY_UP:
        {
            m_selection = --m_selection < 0 ? NUM_CHOICES-1 : m_selection;
        } break;
        case KEY_DOWN:
        {
            ++m_selection;
            m_selection = m_selection % NUM_CHOICES;
        } break;
        case ENTER:
        {
            if(m_selection == BORDERS)
                m_borders = !m_borders;
            else
                m_active = false;
        } break;
    }
}

bool
Menu::borders_on() const {
    return m_borders;
}

bool
Menu::active() const {
    return m_active;
}

bool
Menu::quited() const {
    return m_selection == QUIT;
}

void
Menu::reset() {
    m_active = true;
    m_selection = 0;
}
