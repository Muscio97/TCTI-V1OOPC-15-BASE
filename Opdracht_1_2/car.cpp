#include "car.hpp"

car::car(window & w, int version):
    w(w), version(version),
            roof            ( w, 35, 5, 65, 15 ),
        headlight       ( w, 80, 15, 85, 20 ),
        backlight       ( w, 22, 15, 24, 22 ),
        backglass_line  ( w, 25, 15, 35, 5 ),
        frontglass_line ( w, 65, 5, 75, 15 ),
        box             ( w, 22, 15, 85, 25 ),
       wheel1          ( w, 35, 30, 5 ),
       wheel2          ( w, 75, 30, 5 ),
       wheel3          ( w, 35, 30, 3 ),
       wheel4          ( w, 75, 30, 3 ),
       wheel1_rim      ( w, 35, 30, 4 ),
       wheel2_rim      ( w, 75, 30, 4 ),
       wheel3_rim      ( w, 35, 30, 2 ),
       wheel4_rim      ( w, 75, 30, 2 )
{}

   
void car::draw()
   {
        roof.print(); 
        headlight.print();  
        backlight.print();
        backglass_line.print();
        frontglass_line.print();
        box.print();
        wheel1.print();
        wheel2.print();
        wheel3.print();
        wheel4.print();
        
        if(version==1)
        {
            wheel1_rim.print();
            wheel2_rim.print();
            wheel3_rim.print();
            wheel4_rim.print();
        }
   }
   
