#include "victim.hpp"
#include "filled_rectangle.hpp"
#include "stdio.h"
#include "stdbool.h"

victim::victim(window & w, vector location, vector end, vector d):
rectangle(w, location, end, d)


{}

void victim::interact( drawable & other ){
   if( this != & other){
      if( overlaps( other )){
          static int i = 1;
          if(i==10)
            {
            printf("Victim: Verkleining zou nu klaar moeten zijn\n");
           
          }
           else{printf("Victim: Verkleining nummer %d\n", i++);}        
      }
   }
}


    


