#pragma once

#include <boost/spirit/home/x3.hpp>

#include "ast.h"
#include "ast_adapted.h"
#include "parser.h"

namespace parser {

namespace x3 = boost::spirit::x3;

x3::rule<class Expression, ast::Expression> const Expression = "Expression";
x3::rule<class Sets, std::vector<ast::Set>> const Sets = "Sets";

const auto Filename = x3::lexeme[+(x3::ascii::alnum | x3::char_('_') |
                                   x3::char_('.') | x3::char_('/'))];
const auto Operator = x3::string("EQ") | x3::string("LE") | x3::string("GR");
const auto Set = Filename | Expression;

const auto Expression_def = "[" >> Operator >> x3::int_ >> Sets >> "]";
const auto Sets_def = +(Set);

BOOST_SPIRIT_DEFINE(Expression, Sets);

}  // namespace parser

parser::ExpressionType ExpressionParser() { return parser::Expression; }

