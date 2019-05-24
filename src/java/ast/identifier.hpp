#include <string>
#include <vector>
#include <stdexcept>

#pragma once

using namespace std;

namespace spectrum::java::ast {
  class Identifier {
    public:
      Identifier(const string&);
      ~Identifier() = default;
      const string& name() const;

    private:
      string _name;
  };

  class QualifiedIdentifier {
    public:
      QualifiedIdentifier(const string&);
      QualifiedIdentifier(const vector<string>&);
      QualifiedIdentifier(const vector<Identifier>&);
      ~QualifiedIdentifier() = default;
      const vector<Identifier>& identifiers() const;

    private:
      vector<Identifier> _ids;
  };

  class QualifiedIdentifierList {
    public:
      QualifiedIdentifierList(const vector<string>&);
      QualifiedIdentifierList(const vector<QualifiedIdentifier>&);
      ~QualifiedIdentifierList() = default;
      const vector<QualifiedIdentifier>& qualifiedIdentifiers() const;

    private:
      vector<QualifiedIdentifier> _qids;
  };
}
