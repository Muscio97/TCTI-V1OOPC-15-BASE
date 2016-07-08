#include "victim.hpp"


victim::victim(window & w, vector start, vector end, vector d):
   drawable( w, start, end - start, d),
   end( end ),
   start(start),
   left(   w, vector( start.x, start.y ), vector( start.x, end.y   ) ),
   right(  w, vector( end.x,   start.y ), vector( end.x,   end.y   ) ),
   top(    w, vector( start.x, start.y ), vector( end.x,   start.y ) ),
   bottom( w, vector( start.x, end.y   ), vector( end.x,   end.y   ) )
{};

// varibles for resizing victem
int sides = 0;         //size vactor for sides (left, right)
int tops = 0;           //size vactor for tops (top, bottom)


void victim::interact( drawable & other ){
   if( this != & other)
   {
      if( overlaps( other ))
      { 
          
        //When sides is 18 the victem is at its smalles size, I dont want it to proceed changing its size.
        if(sides<=18)
        {
            
            sides = sides + 2;
            tops = sides/2;
        }
        // changes the location to keep it a regtangle and not some floating lines
        left.location = vector(start.x, start.y+sides);
        right.location = vector(end.x-tops, start.y+sides);
        top.location = vector(start.x, start.y+sides);
        bottom.location = vector(start.x, end.y);
       // changes the size of the lines
        left.end = vector(start.x, end.y);
        right.end = vector(end.x-tops, end.y);
        top.end = vector(end.x-tops, start.y+sides);
        bottom.end = vector(end.x-tops, end.y);
      }
   }
};

void victim::draw(){
   left.draw();
   right.draw();
   top.draw();
   bottom.draw();
}



    


