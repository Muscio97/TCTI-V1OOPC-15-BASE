#include "hwlib.hpp"

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;
   auto ds   = target::pin_out( target::pins::d30 );
   auto shcp = target::pin_out( target::pins::d26 );
   auto stcp = target::pin_out( target::pins::d28 );
   auto spi  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
      stcp, 
      ds, 
      hwlib::pin_in_dummy 
   );
   auto leds = hwlib::hc595( spi, shcp );
   
   hwlib::blink( leds.p0 );
}
