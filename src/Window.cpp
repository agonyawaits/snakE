#include "Window.hpp"
#include "Vector2.hpp"
#include "IDrawable.hpp"
#include "Input.hpp"
#include <ncurses.h>

Window::Window(const Vector2i& size, const Vector2i& position)
    : m_size(size), m_window(newwin(m_size.y(), m_size.x(), position.y(), position.x()))
{
    keypad(m_window, TRUE);
    wattron(m_window, A_BOLD);
    init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(RED, COLOR_RED, COLOR_BLACK);
    init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
}

Window::~Window() {
    delwin(m_window);
}

void Window::clear() const {
    wclear(m_window);
}

Input Window::input() const {
    return Input(wgetch(m_window));
}

Vector2i Window::size() const {
    return m_size;
}

void Window::render(const IDrawable& drawable) const {
    drawable.draw(m_window);
}

void Window::render(const IDrawable& drawable, const Color& color) const {
    wattron(m_window, COLOR_PAIR(color));
    drawable.draw(m_window);
    wattroff(m_window, COLOR_PAIR(color));
}
