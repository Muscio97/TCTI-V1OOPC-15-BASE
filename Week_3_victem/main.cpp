#include "window.hpp"
#include "wall.hpp"
#include "ball.hpp"
#include "victim.hpp"
#include "stdio.h"


int main(){
    printf("Ik kan momenteel waardes aanpassen, maar ik victem niet aanpassen\nIk echo wat de waardes horen te zijn\n");
   int interval = 3;
   window w( vector( 128, 64 ), 2 );
   wall top( w, vector(   0,  0 ), vector( 127,  4 ), interval, vector(1, -1));
   wall right( w, vector( 123,  0 ), vector( 127, 63 ), interval, vector(-1, 1));
   wall bottom( w, vector(   0, 59 ), vector( 127, 63 ), interval, vector(1, -1));
   wall left( w, vector(   0,  0 ), vector(   4, 63 ), interval, vector(-1, 1));
   ball b( w, vector( 50, 20 ), 9, vector( 5, 2 ) );
   victim middle( w, vector(50, 40), vector(60, 58), vector(-1,1));
   
   drawable * objects[] = { &b, &top, &left, &right, &bottom, &middle };

   for(;;){
      w.clear();
      for( auto & p : objects ){
         
         p->draw();
          //printf("test\n");
      }
      wait_ms( 1 );
      for( auto & p : objects ){
          p->update();
      }
      for( auto & p : objects ){
         for( auto & other : objects ){
            p->interact( *other );
         } 
      }
   }
}

