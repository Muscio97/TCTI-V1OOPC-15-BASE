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
       rectangle    roof;
       rectangle    headlight;
       rectangle    backlight;
       line         backglass_line;
       line         frontglass_line;
       rectangle    box;
       circle       wheel1;
       circle       wheel2;
       circle       wheel3;
       circle       wheel4;
       circle       wheel1_rim;
       circle       wheel2_rim;
       circle       wheel3_rim;
       circle       wheel4_rim;

    car( window & w, int version);
    void draw();
    
};



#endif // CAR_HPP
