#define BOOST_TEST_MODULE Identifier Tests
#include <boost/test/included/unit_test.hpp>
#include "java/ast/identifier.h"

using namespace std;
using namespace spectrum::java::ast;

// -- Identifier

BOOST_AUTO_TEST_CASE ( create_identifiers )
{
  vector<string> valid_names {"a", "f1", "_a", "__"};

  for (const string& name : valid_names) {
    Identifier id {name};
    BOOST_TEST( id.name() == name );
  }
}

BOOST_AUTO_TEST_CASE ( create_invalid_identifiers )
{
  vector<string> invalid_names {"1", "1a", ""};

  for (const string& name: invalid_names) {
    BOOST_CHECK_EXCEPTION(
      Identifier {name}, 
      invalid_argument, 
      [=](const exception& ex) { return ex.what() == "Invalid identifier: " + name; }
    );
  }
}

// -- QualifiedIdentifier

void test_QualifiedIdentifier(QualifiedIdentifier& qid)
{
  auto ids = qid.identifiers();

  BOOST_TEST( ids.size() == 3 );
  BOOST_TEST( ids[0].name() == "java" );
  BOOST_TEST( ids[1].name() == "lang" );
  BOOST_TEST( ids[2].name() == "String" );
}

BOOST_AUTO_TEST_CASE ( create_qualified_identifier_from_string )
{
  QualifiedIdentifier qid {"java.lang.String"};
  test_QualifiedIdentifier(qid);
}

BOOST_AUTO_TEST_CASE ( create_qualified_identifier_from_strings )
{
  vector<string> names {"java", "lang", "String"};
  QualifiedIdentifier qid {names};
  test_QualifiedIdentifier(qid);
}

BOOST_AUTO_TEST_CASE ( create_qualified_identifier_from_ids )
{
  Identifier i1 {"java"};
  Identifier i2 {"lang"};
  Identifier i3 {"String"};
  vector<Identifier> ids {i1, i2, i3};
  QualifiedIdentifier qid {ids};
  test_QualifiedIdentifier(qid);
}
