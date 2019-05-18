#include "identifier.h"

using namespace spectrum;

Identifier::Identifier(string name)
{
  // TODO: check regexp
  _name = name;
}

string Identifier::name()
{
  return _name;
}
