#include "calculator.h"

#include <stdexcept>
#include <string>

#include "ast.h"
#include "ast_adapted.h"
#include "ast_calculator.h"
#include "parser.h"

namespace x3 = boost::spirit::x3;

std::set<int> calculate(const std::string& command) {
  auto expression_parser = ExpressionParser();
  ast::Expression ast_expression;
  auto start = command.begin();
  auto end = command.end();
  const auto result = x3::phrase_parse(start, end, expression_parser,
                                       x3::ascii::space, ast_expression);

  if (!result || (start != end)) {
    throw std::logic_error("Cannot parse command");
  }

  return ast::Calculator()(ast_expression);
}
