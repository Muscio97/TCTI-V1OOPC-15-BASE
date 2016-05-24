#ifndef WALL_HPP
#define WALL_HPP
#include "rectangle.hpp"
#include "vector.hpp"
#include "stdbool.h"


class wall : public rectangle
{
private:
bool filled = true;
int update_interval;
int update_count = 0;

public:
    wall (window & w, vector location, vector  end, int update_interval);
    void draw() override;
    void update() override;
};

#endif 
