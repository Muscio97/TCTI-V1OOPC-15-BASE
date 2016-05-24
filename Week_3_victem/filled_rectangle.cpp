#include "Filled_Rectangle.hpp"


Filled_Rectangle::Filled_Rectangle(window & w, int start_x, int start_y, int end_x, int end_y ):
    w(w),
    start_x(start_x),
    start_y(start_y),
    end_x(end_x),
    end_y(end_y)
    
    {}

void Filled_Rectangle::print(){
  
    for(int x = start_x; x < end_x; x++)
    {
        for(int y = start_y; y < end_y; y++)
        {
            
                w.draw(vector(x,y));
        }
        
        
    }
        

}


    
    



