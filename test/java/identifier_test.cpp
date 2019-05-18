#define BOOST_TEST_MODULE Identifier Tests
#include <boost/test/included/unit_test.hpp>
#include "java/identifier.h"

using namespace spectrum;
//using namespace std::literals;

BOOST_AUTO_TEST_CASE ( create_normal_identifiers )
{
  Identifier id {"first_name"};

  BOOST_TEST( id.name() == "first_name" );
}
