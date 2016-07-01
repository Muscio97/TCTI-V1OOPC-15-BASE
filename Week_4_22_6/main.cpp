#include "hwlib.hpp"
#include "pin_out_decorator.hpp"

class pin_out_all : public hwlib::pin_out {
private:
   hwlib::pin_out * list[ 4 ];     
   
public:

   pin_out_all( 
      hwlib::pin_out & p0, 
      hwlib::pin_out & p1 = hwlib::pin_out_dummy,  
      hwlib::pin_out & p2 = hwlib::pin_out_dummy, 
      hwlib::pin_out & p3 = hwlib::pin_out_dummy 
   ):
      list{ &p0, &p1, &p2, &p3 }
   {}
   
   void set( bool v ){
      for( auto p  : list ){
          p->set( v );
      }
   }
};

class pin_out_invert : public hwlib::pin_out {
private:
   hwlib::pin_out & slave;
   
public:
   pin_out_invert( hwlib::pin_out & slave ): 
      slave( slave ){}
   
   void set( bool x ) override {
      slave.set( ! x );
   }  
};

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
    auto hc595 = hwlib::hc595( spi, stcp );

   auto led0_pin = target::pin_out( target::pins::d8 );
   auto led1_pin = target::pin_out( target::pins::d9 );
   auto led2_pin = target::pin_out( target::pins::d10 );
   auto led3_pin = target::pin_out( target::pins::d11 );
   
   auto led0     = pin_out_invert( led0_pin );
   auto led1     = pin_out_invert( led1_pin );
   auto led2     = pin_out_invert( led2_pin );
   auto led3     = pin_out_invert( led3_pin );
   
   auto leds = pin_out_all( led0, led1, led2, led3 );
   
    auto leds2 = pin_out_all( 
      hc595.p4, 
      hc595.p5, 
      hc595.p6,
      hc595.p7
   );
  
    auto leds3 = pin_out_all(
    leds,
    leds2
   );
   
    hwlib::blink(leds3);

}