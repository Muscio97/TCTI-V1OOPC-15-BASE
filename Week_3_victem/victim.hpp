#ifndef VICTIM_HPP
#define VICTIM_HPP
#include "rectangle.hpp"
#include "vector.hpp"
#include "stdbool.h"
#include <iostream>


class victim : public rectangle
{
private:


public:
    victim (window & w, vector location, vector  end, vector d);
    void interact( drawable & other ) override;

};

#endif 
