#include <string>

#pragma once

namespace spectrum {
  using namespace std;

  class Identifier {
    public:
      Identifier(string);
      ~Identifier() = default;
      string name();

    private:
      std::string _name;
  };
}
