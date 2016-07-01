#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>

#include "window.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "Filled_Rectangle.hpp"


class car
{
private: 
    int version;
    window & w;
public:

    car( window & w, int version);
    void draw();
    
};



#endif // CAR_HPP
