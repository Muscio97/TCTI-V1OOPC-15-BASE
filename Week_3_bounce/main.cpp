#include "window.hpp"
#include "wall.hpp"
#include "ball.hpp"

int main(){
   int interval = 3;
   window w( vector( 128, 64 ), 2 );
   wall top( w, vector(   0,  0 ), vector( 127,  4 ), interval, vector(1, -1));
   wall right( w, vector( 123,  0 ), vector( 127, 63 ), interval, vector(-1, 1));
   wall bottom( w, vector(   0, 59 ), vector( 127, 63 ), interval, vector(1, -1));
   wall left( w, vector(   0,  0 ), vector(   4, 63 ), interval, vector(-1, 1));
   ball b( w, vector( 50, 20 ), 9, vector( 5, 2 ) );
   
   drawable * objects[] = { &b, &top, &left, &right, &bottom };

   for(;;){
      w.clear();
      for( auto & p : objects ){
         p->draw();
      }
      wait_ms( 200 );
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

