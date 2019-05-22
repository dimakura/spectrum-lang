#include <catch2/catch.hpp>
#include "java/ast/type.hpp"

using namespace std;
using namespace spectrum::java::ast;

// -- BasicType

TEST_CASE ( "Basic type" )
{
  const vector<string> valid_types {"byte", "short", "char", "int", "long", "float", "double", "boolean"};

  for (const string name : valid_types) {
    const BasicType type(name);
    REQUIRE ( type.name() == name );
  }
}

TEST_CASE ( "Invalid basic types" )
{
  const vector<string> invalid_types {"Byte", "Shor", "har", "integer"};

  for (const string name : invalid_types) {
    REQUIRE_THROWS_WITH ( BasicType(name), "Invalid basic type: " + name );
  }
}
