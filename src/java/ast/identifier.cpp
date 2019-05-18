#include "identifier.h"
#include <regex>
#include <stdexcept>

using namespace std;
using namespace spectrum::java::ast;

const regex name_regex(R"(^[a-z_]\w*)", regex_constants::icase);

Identifier::Identifier(string name) : _name {name}
{
  if (!regex_match(name, name_regex)) {
    throw invalid_argument("Invalid identifier: " + name);
  }
}

string Identifier::name()
{
  return _name;
}
