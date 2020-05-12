#include "Input.hpp"
#include "Direction.hpp"
#include <ncurses.h>

Input::Input(const int& input)
    : m_input(input)
{
}

Direction Input::direction() const {
    switch (m_input) {
        case KEY_LEFT:
            return Direction::LEFT;

        case KEY_RIGHT:
            return Direction::RIGHT;

        case KEY_UP:
            return Direction::UP;

        case KEY_DOWN:
            return Direction::DOWN;

        default:
            return Direction::NONE;
    }
}
