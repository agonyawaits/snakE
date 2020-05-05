#include "Window.hpp"
#include "Vector2.hpp"
#include "Board.hpp"
#include <ncurses.h>

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

void Window::render(const Board& board) const {
    board.draw(m_window);
}

void Window::render(const Object& object, const chtype symbol) const {
    object.draw(m_window, symbol);
}

void Window::render(const Snake& snake) const {
    snake.draw(m_window);
}

int Window::getInput() const {
    return wgetch(m_window);
}

Vector2i Window::size() const {
    return m_size;
}
