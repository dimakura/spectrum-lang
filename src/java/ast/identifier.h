#include <string>
#include <vector>
#include <stdexcept>

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

  class QualifiedIdentifier {
    public:
      QualifiedIdentifier(const string&);
      QualifiedIdentifier(const vector<string>& names);
      QualifiedIdentifier(const vector<Identifier>& ids);
      ~QualifiedIdentifier() = default;
      vector<Identifier> identifiers();

    private:
      vector<Identifier> _ids;
  };
}
