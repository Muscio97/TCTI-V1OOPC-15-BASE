#include "victim.hpp"
#include "filled_rectangle.hpp"
#include "stdio.h"

victim::victim(window & w, vector location, vector end, vector d):
rectangle(w, location, end, d)


{}

void victim::interact( drawable & other ){
   if( this != & other){
      if( overlaps( other )){
          static int i = 0;
          printf("%d halp\n", i);
          vector a = vector(50, 40);
          vector b = vector(60, 58);
      }
   }
}


    


