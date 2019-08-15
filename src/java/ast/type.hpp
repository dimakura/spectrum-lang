#include <string>
#include <vector>

#pragma once

using namespace std;

namespace spectrum::java::ast {
  class BasicType {
    public:
      BasicType(const string&);
      ~BasicType() = default;
      const string& name() const;

    private:
      string _name;
  };
}
