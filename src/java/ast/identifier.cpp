#include <regex>
#include <boost/algorithm/string.hpp>
#include "identifier.hpp"

using namespace std;
using namespace spectrum::java::ast;

// -- Identifier

static const regex id_regex(R"(^[a-z_]\w*$)", regex_constants::icase);

Identifier::Identifier(const string& name) : _name {name}
{
  if (!regex_match(name, id_regex)) {
    throw invalid_argument("Invalid identifier: " + name);
  }
}

const string& Identifier::name() const
{
  return _name;
}

// -- QualifiedIdentifier

void init_QualifiedIdentifier(const vector<string>& names, vector<Identifier>& ids)
{
  for (auto name : names)
    ids.push_back(Identifier {name});
}

QualifiedIdentifier::QualifiedIdentifier(const string& ids)
{
  vector<string> names;
  boost::split(names, ids, boost::is_any_of("."));

  init_QualifiedIdentifier(names, _ids);
}

QualifiedIdentifier::QualifiedIdentifier(const vector<string>& names)
{
  init_QualifiedIdentifier(names, _ids);
}

QualifiedIdentifier::QualifiedIdentifier(const vector<Identifier>& ids)
{
  for (auto id : ids)
    _ids.push_back(id);
}

const vector<Identifier>& QualifiedIdentifier::identifiers() const
{
  return _ids;
}

// -- QualifiedIdentifierList

QualifiedIdentifierList::QualifiedIdentifierList(const vector<string>& qids)
{
  for (auto qid : qids)
    _qids.push_back(QualifiedIdentifier {qid});
}

QualifiedIdentifierList::QualifiedIdentifierList(const vector<QualifiedIdentifier>& qids)
{
  for (auto qid : qids)
    _qids.push_back(qid);
}

const vector<QualifiedIdentifier>& QualifiedIdentifierList::qualifiedIdentifiers() const
{
  return _qids;
}
