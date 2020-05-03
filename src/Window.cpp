#include "Window.hpp"
#include "Vector2.hpp"
#include <ncurses.h>

Window::Window(const int& h, const int& w, const Vector2i& position)
    : m_height(h), m_width(w), m_position(position),
    m_window(newwin(m_height, m_width, m_position.y(), m_position.x()))
{
}

Window::~Window() {
    delwin(m_window);
}
