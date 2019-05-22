#include <catch2/catch.hpp>
#include "java/ast/identifier.hpp"

using namespace std;
using namespace spectrum::java::ast;

// -- Identifier

TEST_CASE ( "Identifiers" )
{
  const vector<string> valid_names {"a", "f1", "_a", "__", "a_b", "a1b", "A", "B1"};

  for (const string& name : valid_names) {
    const Identifier id {name};
    REQUIRE ( id.name() == name );
  }
}


TEST_CASE ( "Invalid identifiers" )
{
  const vector<string> invalid_names {"1", "1a", "", "a b"};

  for (const string& name: invalid_names) {
    REQUIRE_THROWS_WITH ( Identifier {name},  "Invalid identifier: " + name );
  }
}

// -- QualifiedIdentifier

void test_QualifiedIdentifier(const QualifiedIdentifier& qid)
{
  const auto ids = qid.identifiers();

  REQUIRE ( ids.size() == 3 );
  REQUIRE ( ids[0].name() == "java" );
  REQUIRE ( ids[1].name() == "lang" );
  REQUIRE ( ids[2].name() == "String" );
}

TEST_CASE ( "Qualified Identifier: single string" )
{
  const QualifiedIdentifier qid {"java.lang.String"};
  test_QualifiedIdentifier(qid);
}


TEST_CASE ( "Qualified Identifier: array of strings" )
{
  const vector<string> names {"java", "lang", "String"};
  const QualifiedIdentifier qid {names};
  test_QualifiedIdentifier(qid);
}


TEST_CASE ( "Qualified Identifier: array of identifiers" )
{
  const Identifier i1 {"java"};
  const Identifier i2 {"lang"};
  const Identifier i3 {"String"};
  const vector<Identifier> ids {i1, i2, i3};
  const QualifiedIdentifier qid {ids};
  test_QualifiedIdentifier(qid);
}

// -- QualifiedIdentifierList

TEST_CASE ( "Qualified Identifier List: array of strings" )
{
  const vector<string> data {"java.lang.String", "java.utils.List"};
  const QualifiedIdentifierList list {data};
  const auto qids = list.qualifiedIdentifiers();

  REQUIRE( qids.size() == 2 );
  test_QualifiedIdentifier(qids[0]);
}

TEST_CASE ( "Qualified Identifiers List: array of qualified identifiers" )
{
  const QualifiedIdentifier q1 {"java.lang.String"};
  const QualifiedIdentifier q2 {"java.utils.List"};
  const vector<QualifiedIdentifier> data {q1, q2};
  const QualifiedIdentifierList list {data}; 
  const auto qids = list.qualifiedIdentifiers();

  REQUIRE( qids.size() == 2 );
  test_QualifiedIdentifier(qids[0]);
}
