#pragma once

#include <set>

#include "ast.h"

namespace ast {
struct Calculator {
  std::set<int> operator()(const ast::Expression& expression);
  std::set<int> operator()(const std::string& filename);
};
}  // namespace ast

