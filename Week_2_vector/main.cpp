#include "ostream"
#include "catch_with_main.hpp"
#include "vector.hpp"

/*TEST_CASE( "multiply vector into vector; return value" ){
   vector v( 3, 10 );
   vector x = ( v *= vector( 1, 2 )); 
   REQUIRE( x == vector( 3, 20 ) );     
}
*/

TEST_CASE( "Add a vector to a vector" ){
   vector v( 3, 10 ), r(0, 10);
   vector x = v + r; 
   REQUIRE(x == vector( 3, 20 ));     
}

TEST_CASE( "change add a vector to a vector" ){
   vector v( 3, 10 );
   vector x = (v+= vector(0, 10)); 
   REQUIRE(x == vector( 3, 20 ));     
}

TEST_CASE( "subtract a vector from a vector" ){
   vector v( 3, 10 ), r(0, 10);
   vector x = v - r; 
   REQUIRE(x == vector( 3, 0 ));     
}

TEST_CASE( "change subtract a vector from a vector" ){
   vector v( 3, 10 );
   vector x = (v-= vector(0, 10)); 
   REQUIRE(x == vector( 3, 0 ));     
}

TEST_CASE( "multiply a vector with a vector" ){
   vector v( 3, 10 ), r(2, 10);
   vector x = v * r; 
   REQUIRE(x == vector( 6, 100 ));     
}

TEST_CASE( "change multiply a vector with a vector" ){
   vector v( 3, 10 );
   vector x = (v*= vector(2, 2)); 
   REQUIRE(x == vector( 6, 20 ));     
}

TEST_CASE( "divid a vector with a vector" ){
   vector v( 3, 10 ), r(1, 10);
   vector x = v / r; 
   REQUIRE(x == vector( 3, 1 ));     
}

TEST_CASE( "change subtract a vector with a vector" ){
   vector v( 33, 10 );
   vector x = (v/= vector(11, 5)); 
   REQUIRE(x == vector( 3, 2 ));     
}



