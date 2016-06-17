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
   
   led0.direction_set_output();
   led1.direction_set_output();
   led2.direction_set_output();
   led3.direction_set_output();
   while(1){
      led0.set( 1 );
      led1.set( 0 );
      led2.set( 0 );
      led3.set( 0 );
      
      hwlib::wait_ms( 200 ); 
      led0.set( 1 );
      led1.set( 1 );
      led2.set( 0 );
      led3.set( 0 );
      
      hwlib::wait_ms( 200 );
      led0.set( 0 );
      led1.set( 1 );
      led2.set( 1 );
      led3.set( 0 );
      
      hwlib::wait_ms( 200 );  
      led0.set( 0 );
      led1.set( 0 );
      led2.set( 1 );
      led3.set( 1 );
      
      hwlib::wait_ms( 200 );    
      led0.set( 0 );
      led1.set( 0 );
      led2.set( 0 );
      led3.set( 1 );
      
      hwlib::wait_ms( 200 ); 
      led0.set( 0 );
      led1.set( 0 );
      led2.set( 0 );
      led3.set( 0 );
      
      hwlib::wait_ms( 200 );    
   }
}
