// ==========================================================================
//
// blink a led on PIOB pin 27 == arduino-due on-board LED
//
// This file is in the public domain.
//
// ==========================================================================

#include "hwlib.hpp"

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
    auto led0 = hwlib::target::pin_in_out( hwlib::target::pins::d8 );
    auto led1 = hwlib::target::pin_in_out( hwlib::target::pins::d9 );
    auto led2 = hwlib::target::pin_in_out( hwlib::target::pins::d10 );
    auto led3 = hwlib::target::pin_in_out( hwlib::target::pins::d11 );
    
    auto pin0 = hwlib::target::pin_in_out( hwlib::target::pins::d24 );
    auto pin1 = hwlib::target::pin_in_out( hwlib::target::pins::d22 );

   
   led0.direction_set_output();
   led1.direction_set_output();
   led2.direction_set_output();
   led3.direction_set_output();
    
    pin0.direction_set_input();
    pin1.direction_set_input();


   int x = 0; 
   
   while(1){
       
        hwlib::wait_ms(100);
      if(pin0.get())
      { 
        x++;
        hwlib::cout << hwlib::dec << (int)x;
        hwlib::wait_ms(500);
      }      
      
      if(pin1.get())
      { 
        hwlib::cout << hwlib::dec << (int)x;
        x--;
        hwlib::wait_ms(500);
      }
      
      if(x<0){x=0;}
      if(x>4){x=4;}
      
      if(x>=1){led0.set( 1 );}
      if(x>=2){led1.set( 1 );}
      if(x>=3){led2.set( 1 );}
      if(x>=4){led3.set( 1 );}
      
      
      if(x<1){led0.set( 0 );}
      if(x<2){led1.set( 0 );}
      if(x<3){led2.set( 0 );}
      if(x<4){led3.set( 0 );}
      

   }
}
