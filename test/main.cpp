#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

double plus(double a, double b)
{
  return a + b;
}

TEST_CASE("Two numbers get added") {
  REQUIRE( plus(1, 1) == 2 );
  REQUIRE( plus(1, 10) == 11 );
}
