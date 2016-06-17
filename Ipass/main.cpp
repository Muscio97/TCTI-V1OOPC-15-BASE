//===========================================================//
//             Copyright Mike Hilhorst 2016.                 //
// Distributed under the Boost Software License, Version 1.0.//
//    (See accompanying file LICENSE_1_0.txt or copy at      //
//          http://www.boost.org/LICENSE_1_0.txt)            //
//===========================================================//
 
#include "hwlib.hpp"
#include "MAX7219.hpp"
int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;
   auto din   = target::pin_out( target::pins::d5 );
   auto cs = target::pin_out( target::pins::d6 );
   auto clk = target::pin_out( target::pins::d7 );
   auto spi  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
      clk, 
      din, 
      hwlib::pin_in_dummy 
   );
    
    MAX7219(spi, cs);
}
