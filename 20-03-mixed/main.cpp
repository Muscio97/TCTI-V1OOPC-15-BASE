#include "hwlib.hpp"

int main( void ){	
    
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;
   
   auto ds   = target::pin_out( target::pins::d7 );
   auto shcp = target::pin_out( target::pins::d5 );
   auto stcp = target::pin_out( target::pins::d6 );
   auto spi  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
      stcp, 
      ds, 
      hwlib::pin_in_dummy 
   );
   auto hc595 = hwlib::hc595( spi, shcp );
   
   auto led0 = target::pin_out( target::pins::d8 );
   auto led1 = target::pin_out( target::pins::d9 );
   auto led2 = target::pin_out( target::pins::d10 );
   auto led3 = target::pin_out( target::pins::d11 );
   
   auto leds = hwlib::port_out_from_pins( 
      led0, 
      led1, 
      led2, 
      led3,
      hc595.p0, 
      hc595.p1, 
      hc595.p2 
   );
   hwlib::kitt( leds );    
}
