#include <ncurses.h>
#include "window.h"
#include "v2.h"
#include "idrawable.h"

Window::Window() {
    initscr();
    noecho();
    curs_set(0);
    halfdelay(1);
    start_color();

    m_size = {COLS, LINES};
    m_window = newwin(m_size.y, m_size.x, 0, 0);
    keypad(m_window, TRUE);

    init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(RED, COLOR_RED, COLOR_BLACK);
    init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
}

Window::~Window() {
    delwin(m_window);
    endwin();
}

void
Window::clear() const {
    wclear(m_window);
}

Input::Input(int input) : m_input(input) {
}

int
Input::key() const {
    return m_input;
}

Direction
Input::direction() const {
    switch(m_input) {
        case KEY_LEFT:  return LEFT;
        case KEY_RIGHT: return RIGHT;
        case KEY_UP:    return UP;
        case KEY_DOWN:  return DOWN;
        default:        return NONE;
    }
}

Input
Window::input() const {
    return { wgetch(m_window) };
}

V2
Window::size() const {
    return m_size;
}

void
Window::render(const IDrawable &drawable) const {
    drawable.draw(m_window);
}

void
Window::render(const IDrawable &drawable, Color color) const {
    wattron(m_window, A_BOLD);
    wattron(m_window, COLOR_PAIR(color));
    drawable.draw(m_window);
    wattroff(m_window, COLOR_PAIR(color));
    wattroff(m_window, A_BOLD);
}
