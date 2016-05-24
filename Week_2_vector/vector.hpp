#ifndef RATIONAL_HPP
#define RATIONAL_HPP
#include <iomanip>
#include "iostream"
/// @file

/// vector ADT
//
/// This is an ADT that implements vector (fractional) values.
/// The x and y are stored as two (signed) integers.
/// The appropriate constructors and operators are provided.
class vector {
public:
   int x;
   int y;
   /// constructor from explicit values
   //
   /// The constructor does not initialize the values
   vector():
        x(), y()
   {}
   
   /// The constructor does initialize the values
   vector(int x, int y):
        x(x), y(y)
   {}
   
   /// compare two vector values
   //
   /// This operator tests for equality. It returns true
   /// if and only if the x and denminator of both
   /// operands are equal.
   bool operator==( const vector & rhs ) const {
      return ( x == rhs.x ) && ( y == rhs.y );
   }

   /// output operator for a vector value
   //
   /// This operator<< prints a constructor in the format
   /// [x/y] where both values are printed as
   /// decimal values.
  friend std::ostream & operator<<( std::ostream & lhs, const vector & rhs ){
      return lhs 
         << "[" 
         << rhs.x 
         << "/" 
         << rhs.y
         << "]";
   }   
   
   
   /// multiply a vector by an integer
   //
   /// This operator* multiplies a vector value by an integer value.
   vector operator*( const int rhs ) const {
      return vector( x * rhs, y);
   }
   
   /// multiply a vector by a vector
   //
   /// This operator* multiplies a vector value by a vector value.
   vector operator*( const vector & rhs ) const {
      return vector( 
         x * rhs.x,
         y * rhs.y
        
      );
   }
   
   /// add a vector to another vector
   //
   /// This operator+ adds a vector value a vector variable.
  vector operator+( const vector rhs ) const {
    return vector ( x + rhs.x, y + rhs.y);
   }

    /// add a vector to another vector
   //
   /// This operator+= adds a vector value a vector variable.
   vector & operator+=( const vector & rhs ) {
      x = x + rhs.x;
      y = y + rhs.y;
      
      return *this;
   }
   
    /// subtract a vector to another vector
   //
   /// This operator- subtracts a vector value a vector variable.
  vector operator-( const vector rhs ) const {
    return vector ( x - rhs.x, y - rhs.y);
   }
   
    /// subtract a vector to another vector
   //
   /// This operator-= subtracts a vector value a vector variable.
   vector & operator-=( const vector & rhs ) {
      x = x - rhs.x;
      y = y - rhs.y;
      
      return *this;
   }
   
    /// multiply a vector by a int
   //
   /// This operator* multiplies a vector by a int value.
    vector operator*( const vector rhs ){
       return vector (x * rhs.x, y * rhs.y);
    }
      
       /// multiply a vector by a int
   //
   /// This operator*= multiplies a vector by a int value.
      vector operator*=( const vector & rhs ){
      x = x * rhs.x;
      y = y * rhs.y;
      
      return *this;
   }
   
    /// dividing a vector by a int
   //
   /// This operator/ divids a vector by a int value.
    vector operator/( const vector rhs ){
       return vector (x / rhs.x, y / rhs.y);
    }
      
    /// multiply a vector by a int
   //
   /// This operator/= divids a vector by a int value.
      vector operator/=( const vector & rhs ){
      x = x / rhs.x;
      y = y / rhs.y;
      
      return *this;
   }
};
  /* vector operator+( const vector lhs,  const vector rhs)
   {
    return vector ( lhs.x + rhs.x, lhs.y + rhs.y);
   };
    * */

#endif

