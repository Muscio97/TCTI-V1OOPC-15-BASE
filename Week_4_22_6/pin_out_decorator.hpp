#ifndef PIN_OUT_DECORATOR_HPP
#define PIN_OUT_DECORATOR_HPP
#include "hwlib.hpp"
class pin_out_decorator
{
private:
    
    hwlib::hc595 leds;
    hwlib::target::pin_in_out led0;
    hwlib::target::pin_in_out led1;
    hwlib::target::pin_in_out led2;
    hwlib::target::pin_in_out led3;
    int ms;


public:
    pin_out_decorator(hwlib::hc595 leds,hwlib::target::pin_in_out led0, hwlib::target::pin_in_out led1, hwlib::target::pin_in_out led2, hwlib::target::pin_in_out led3, int ms):
    leds(leds),led0(led0), led1(led1), led2(led2), led3(led3), ms(ms)
    {}
    
    void kitt()
    {

          led0.set( 1 );
          led1.set( 1 );
          led2.set( 1 );
          led3.set( 1 );
  
            leds.set( 0b00000000 );
          hwlib::wait_ms( ms );
          led0.set( 0 );
          led1.set( 0 );
          led2.set( 0 );
          led3.set( 0 );
                  leds.set( 0b11111111 );
         hwlib::wait_ms( ms );
    }

};

#endif // PIN_OUT_DECORATOR_HPP
