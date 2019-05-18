#include <string>

#pragma once

using namespace std;

namespace spectrum::java::ast {
  class Identifier {
    public:
      Identifier(string);
      ~Identifier() = default;
      string name();

    private:
      string _name;
  };
}
