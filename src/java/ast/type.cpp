#include "type.h"
#include <regex>

using namespace std;
using namespace spectrum::java::ast;

// -- BasicType

const regex basic_regex(R"(^(byte|short|char|int|long|float|double|boolean)$)");

BasicType::BasicType(string name) : _name {name}
{
  if (!regex_match(name, basic_regex))
    throw new invalid_argument("Invalid basic type: " + name);
}

string BasicType::name()
{
  return _name;
}
