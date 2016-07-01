// template

#include <iostream>

#include "window.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "Filled_Rectangle.hpp"
#include "car.hpp"

int main(int argc, char **argv){
   window w( 100, 50, 2 );
   //0 digit is the version
   // 0 = normal wheels
   // 1 = tyres on wheels 
   
   car car1( w, 1);
   car1.draw();
  
   
   
   
   
   return 0;
}
