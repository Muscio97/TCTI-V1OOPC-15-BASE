#include "hwlib.hpp"
#ifndef PIN_DECORATOR_HPP
#define PIN_DECORATOR_HPP


class pin_decorator: public hwlib::pin_in
{
private:
auto pin1;
auto pin2;

public:
pin_decorator( hwlib::pin_in & pin1, hwlib::pin_in & pin2):
    pin1(pin1), pin2(pin2)
    {}
    
    bool get()
    {
        
        if( pin1.get() && pin2.get() == 1)
        {
           return 1;
        }
        else
        {   
            return 0;
        }
    }

};

#endif // PIN_DECORATOR_HPP
