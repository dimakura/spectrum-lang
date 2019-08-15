#include <regex>
#include <stdexcept>
#include "type.hpp"

using namespace std;
using namespace spectrum::java::ast;

// -- BasicType

static const regex basic_type_regex(R"(^(byte|short|char|int|long|float|double|boolean)$)");

BasicType::BasicType(const string& name) : _name {name}
{
  if (!regex_match(name, basic_type_regex))
    throw invalid_argument("Invalid basic type: " + name);
}

const string& BasicType::name() const
{
  return _name;
}
