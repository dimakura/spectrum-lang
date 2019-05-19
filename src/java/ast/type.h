#include <string>
#include <vector>
#include <stdexcept>

#pragma once

using namespace std;

namespace spectrum::java::ast {
  class BasicType {
    public:
      BasicType(string);
      ~BasicType() = default;
      string name();

    private:
      string _name;
  };
}
