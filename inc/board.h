#pragma once

#include "v2.h"
#include "idrawable.h"
#include <ncurses.h>

struct Board : public IDrawable {
    Board(const V2 &size, const V2 &position);

    void    draw(WINDOW *) const override;
    V2      size() const;
    V2      position() const; 
    V2      spot() const;
    
private:
    V2 m_position;
    V2 m_size;
};
