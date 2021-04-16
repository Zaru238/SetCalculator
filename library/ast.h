#pragma once

#include <boost/spirit/home/x3/support/ast/variant.hpp>
#include <string>
#include <vector>

namespace ast {

namespace x3 = boost::spirit::x3;

struct Expression;

struct Set : x3::variant<std::string, x3::forward_ast<Expression>> {
  using base_type::base_type;
  using base_type::operator=;
};

struct Expression {
  std::string operator_;
  int n_;
  std::vector<Set> sets_;
};

}  // namespace ast
