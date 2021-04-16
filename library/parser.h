#pragma once

#include <boost/spirit/home/x3.hpp>

#include "ast.h"

namespace parser {
namespace x3 = boost::spirit::x3;

using ExpressionType = x3::rule<class Expression, ast::Expression>;
BOOST_SPIRIT_DECLARE(ExpressionType);

}  // namespace parser

parser::ExpressionType ExpressionParser();

