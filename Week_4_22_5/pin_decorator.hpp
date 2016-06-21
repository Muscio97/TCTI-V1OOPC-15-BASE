#include "hwlib.hpp"
#ifndef PIN_DECORATOR_HPP
#define PIN_DECORATOR_HPP


class pin_decorator: public hwlib::pin_in
{
private:
    hwlib::target::pin_in_out & pin0;
    hwlib::target::pin_in_out & pin1;

public:
    
    pin_decorator(hwlib::target::pin_in_out & pin0, hwlib::target::pin_in_out & pin1):
    pin0(pin0), pin1(pin1)
    {}
    
    bool get()
    {
        if( pin0.get() && pin1.get() == 1)
        {
           return 1;
        }
        
        return 0;
    }

};

#endif // PIN_DECORATOR_HPP
