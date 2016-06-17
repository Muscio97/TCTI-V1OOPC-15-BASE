#include "ball.hpp"
#include <iostream>
#include "stdio.h"

void ball::update(){
   location += speed;
}

ball::ball( window & w, const vector & midpoint, int radius, const vector & speed ):
   circle( w, midpoint, radius ),
   speed( speed )
{}

void ball::interact( drawable & other ){
   if( this != & other){
      if( overlaps( other )){
         speed.x *= other.d.x;
         speed.y *= other.d.y;
         static int i = 1;
          printf("Ball: Stuiter nummer %d\n", i++);
      }
   }
}