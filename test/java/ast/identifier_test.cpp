#define BOOST_TEST_MODULE Identifier Tests
#include <boost/test/included/unit_test.hpp>
#include "java/ast/identifier.h"

using namespace std;
using namespace spectrum::java::ast;

BOOST_AUTO_TEST_CASE ( create_normal_identifiers )
{
  vector<string> valid_names {"a", "f1", "_a", "__"};

  for (const string& name : valid_names) {
    Identifier id {name};
    BOOST_TEST( id.name() == name );
  }
}

BOOST_AUTO_TEST_CASE ( create_invalid_identifiers )
{
  vector<string> invalid_names {"1", "1a", ""};

  for (const string& name: invalid_names) {
    BOOST_CHECK_EXCEPTION(
      Identifier {name}, 
      invalid_argument, 
      [=](const exception& ex) { return ex.what() == "Invalid identifier: " + name; }
    );
  }
}
