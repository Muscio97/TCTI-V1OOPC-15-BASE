#include "hwlib.hpp"
#include "pin_decorator.hpp"

int main(void){
  namespace target = hwlib::target;

   auto ds   = target::pin_out( target::pins::d7 );
   auto shcp = target::pin_out( target::pins::d6 );
   auto stcp = target::pin_out( target::pins::d5 );
   auto spi  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
      shcp, 
      ds, 
      hwlib::pin_in_dummy 
   );
    auto leds = hwlib::hc595( spi, stcp );

    auto led0 = target::pin_in_out( target::pins::d8 );
    auto led1 = target::pin_in_out( target::pins::d9 );
    auto led2 = target::pin_in_out( target::pins::d10 );
    auto led3 = target::pin_in_out( target::pins::d11 );
    
    auto pin0 = target::pin_in_out( target::pins::d24 );
    auto pin1 = target::pin_in_out( target::pins::d22 );

   led0.direction_set_output();
   led1.direction_set_output();
   led2.direction_set_output();
   led3.direction_set_output();
    
    pin0.direction_set_input();
    pin1.direction_set_input();

    while(1)
    {
    pin_decorator test(pin0, pin1);
    
    hwlib::cout <<hwlib::hex << test.get();
    hwlib::wait_ms(100);
    }
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
      
      if(x<=0){x=0;}
      if(x>=8){x=8;}
      
      if(x>=1){led0.set( 1 );}
      if(x>=2){led1.set( 1 );}
      if(x>=3){led2.set( 1 );}
      if(x>=4){led3.set( 1 );}
      if(x==5){leds.set( 0b00010001 );}
      if(x==6){leds.set( 0b00110011 );}
      if(x==7){leds.set( 0b01110111 );}
      if(x==8){leds.set( 0b11111111 );}
      
      if(x<1){led0.set( 0 );}
      if(x<2){led1.set( 0 );}
      if(x<3){led2.set( 0 );}
      if(x<4){led3.set( 0 );}
      if(x<5){leds.set( 0x00);}
      

   }
}