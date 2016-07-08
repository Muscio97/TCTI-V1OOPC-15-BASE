#ifndef VICTIM_HPP
#define VICTIM_HPP
#include "window.hpp"
#include "drawable.hpp"
#include "vector.hpp"
#include "line.hpp"


class victim : public drawable
{
protected:
public:
   vector end;
   vector start;
   line left;
   line right;
   line top;
   line bottom;
    victim (window & w, vector start, vector  end, vector d);
    void interact( drawable & other ) override;
    void draw() override;

};

#endif 
