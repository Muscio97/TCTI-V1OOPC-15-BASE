#include "wall.hpp"
#include "filled_rectangle.hpp"

wall::wall(window & w, vector location, vector end, int update_interval):
rectangle(w, location, end),
update_interval(update_interval)
{}

void wall::update()
{
    update_count++;
    if(update_count == update_interval)
    {
        if(filled == true)
        {
            filled = false;
        }
        else
        {
            filled = true;
        }
            update_count = 0;
    }
};

void wall::draw()
{
    if(filled == true)
    {
    
        rectangle::draw();
    }
    else
    {
    Filled_Rectangle box( w, location.x, location.y, end.x, end.y );
    box.print();
        
          
        
    }
    
    
    
    
    
};

