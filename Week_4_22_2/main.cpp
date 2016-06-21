#include "hwlib.hpp"

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
    auto led0 = hwlib::target::pin_in_out( hwlib::target::pins::d8 );
    auto led1 = hwlib::target::pin_in_out( hwlib::target::pins::d9 );
    auto led2 = hwlib::target::pin_in_out( hwlib::target::pins::d10 );
    auto led3 = hwlib::target::pin_in_out( hwlib::target::pins::d11 );
   
   led0.direction_set_output();
   led1.direction_set_output();
   led2.direction_set_output();
   led3.direction_set_output();
   byte leds;
   int x = 0; 
   
   while(1){
       
      if(x>4){x=0;}
      hwlib::cout << hwlib::dec << (int)x;
      hwlib::wait_ms(80);
      leds = 1 << x;
      led0.set( leds & 1 );
      led1.set( leds & 2 );
      led2.set( leds & 4 );
      led3.set( leds & 8 );
      x++;
      
     
   }
}
