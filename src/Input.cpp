#include "Input.hpp"
#include "Direction.hpp"
#include <ncurses.h>

Input::Input(const int& input)
    : m_input(input)
{
}

Direction Input::direction() const {
    switch (m_input) {
        case KEY_LEFT:  return LEFT;
        case KEY_RIGHT: return RIGHT;
        case KEY_UP:    return UP;
        case KEY_DOWN:  return DOWN;
        default:        return NONE;
    }
}
