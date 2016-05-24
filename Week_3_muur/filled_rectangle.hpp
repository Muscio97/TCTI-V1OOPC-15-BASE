#ifndef FILLED_RECTANGLE_HPP
#define FILLED_RECTANGLE_HPP

#include "window.hpp"

class Filled_Rectangle
{
private:
    int start_x;
    int start_y;
    int end_x;
    int end_y;
    window & w;
public:
    Filled_Rectangle(window & w, int start_x, int start_y, int end_x, int end_y);
    void print();
};

#endif // FILLED_RECTANGEL_HPP
