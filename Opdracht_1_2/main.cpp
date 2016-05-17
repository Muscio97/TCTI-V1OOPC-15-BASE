// template

#include <iostream>

#include "window.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "Filled_Rectangle.hpp"

int main(int argc, char **argv){
   window w( 200, 50, 2 );
   
  /* line diagonal_line( w, 5, 5, 30, 40 );
   diagonal_line.print();
   
   rectangle box( w, 20, 10, 30, 20 );
   box.print();
   
   Filled_Rectangle box( w, 20, 0, 40, 20 );
   box.print();
   
   circle ball( w, 70, 30, 20 );
   ball.print();*/
   
   rectangle roof( w, 35, 5, 65, 15 );
   roof.print();
   rectangle headlight ( w, 80, 15, 85, 20 );
   headlight.print();
   rectangle backlight ( w, 22, 15, 24, 22 );
   backlight.print();
   line backglass_line( w, 25, 15, 35, 5 );
   backglass_line.print();
   line frontglass_line( w, 65, 5, 75, 15 );
   frontglass_line.print();
   rectangle box( w, 22, 15, 85, 25 );
   box.print();
   circle wheel1( w, 35, 30, 5 );
   wheel1.print();
   circle wheel2( w, 75, 30, 5 );
   wheel2.print();
   circle wheel3( w, 35, 30, 3 );
   wheel3.print();
   circle wheel4( w, 75, 30, 3 );
   wheel4.print();
   
   rectangle roof2( w, 135, 5, 165, 15 );
   roof2.print();
   Filled_Rectangle headlight2 ( w, 180, 15, 185, 20 );
   headlight2.print();
   line frontlight1 ( w, 185, 15, 195, 5 );
   frontlight1.print();
   line frontlight2 ( w , 185, 20, 195, 30 );
   frontlight2.print();
   line frontlight_bar ( w, 195, 5, 195, 30);
   frontlight_bar.print();
   Filled_Rectangle backlight2 ( w, 122, 15, 124, 22 );
   backlight2.print();
   line rearlight1 ( w, 122, 15, 112, 5);
   rearlight1.print();
   line rearlight2  ( w, 122, 22, 112, 32);
   rearlight2.print();
   line rearlight_bar (w , 112, 5, 112, 32);
   rearlight_bar.print();
   line backglass_line2( w, 125, 15, 135, 5 );
   backglass_line2.print();
   line frontglass_line2( w, 165, 5, 175, 15 );
   frontglass_line2.print();
   rectangle box2( w, 122, 15, 185, 25 );
   box2.print();
   circle wheel5( w, 135, 33, 8 );
   wheel5.print();
   circle wheel6( w, 175, 33, 8 );
   wheel6.print();
   circle wheel7( w, 135, 33, 6 );
   wheel7.print();
   circle wheel8( w, 175, 33, 6 );
   wheel8.print();
   
   
   
   
   
   return 0;
}
