#include "victim.hpp"
#include "filled_rectangle.hpp"
#include "stdio.h"
#include "stdbool.h"

victim::victim(window & w, vector location, vector end, vector d):
rectangle(w, location, end, d)
{}

void victim::interact( drawable & other ){
   if( this != & other)
   {
      if( overlaps( other ))
      { 
            if(location.x<=0){location.x = 0;}
            else{location.x = location.x -10;}
            if(location.y<=0){location.y =0;}
            else{location.y = location.y -10;}
            if(end.x<=0){end.x = 0;}
            else{end.x = end.x -10;}
            if(end.y<=0){end.y = 0;}
            else{end.y = end.y -10;}
            printf("location (%d, %d) end(%d, %d)\n", location.x, location.y, end.x, end.y);
      }
   }
}


    


