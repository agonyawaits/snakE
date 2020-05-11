#include "Window.hpp"
#include "Vector2.hpp"
#include "IDrawable.hpp"
#include "Input.hpp"
#include <ncurses.h>
#include <random>

Window::Window(const Vector2i& size, const Vector2i& position)
    : m_size(size), m_window(newwin(m_size.y(), m_size.x(), position.y(), position.x()))
{
    keypad(m_window, TRUE);
}

Window::~Window() {
    delwin(m_window);
}
void Window::clear() const {
    wclear(m_window);
}

void Window::render(const IDrawable& drawable) const {
    drawable.draw(m_window);
    mvwprintw(m_window, m_size.y()-1, 0, "%d", 10);
}

Input Window::getInput() const {
    return Input(wgetch(m_window));
}

Vector2i Window::size() const {
    return m_size;
}

Vector2i Window::randomPosition() const {
    return Vector2i(
        rand() % (m_size.x()-2) + 1,
        rand() % (m_size.y()-2) + 1
    );
}
