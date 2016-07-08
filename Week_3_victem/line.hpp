#ifndef LINE_HPP
#define LINE_HPP

#include "window.hpp"
#include "vector.hpp"
#include "drawable.hpp"

class line : public drawable {
private:
public:
   vector end;

   line( window & w, const vector & location, const vector & end):
      drawable( w, location, end - location),
      end( end )
   {}
   void draw() override;
   void draw_victim(int x0, int y0, int x1, int y1);
};

#endif // LINE_HPP
