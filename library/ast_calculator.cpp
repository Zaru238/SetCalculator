#include "ast_calculator.h"

#include <assert.h>

#include <fstream>
#include <functional>
#include <map>
#include <stdexcept>

namespace ast {
std::set<int> Calculator::operator()(const ast::Expression& expression) {
  std::map<int, int> element2frequency;

  for (const auto& element : expression.sets_) {
    const auto set = boost::apply_visitor(*this, element);
    for (auto element : set) {
      element2frequency[element]++;
    }
  }

  std::function<bool(int)> comparator;

  if (expression.operator_ == "EQ") {
    comparator = [&expression](auto frequency) {
      return frequency == expression.n_;
    };
  } else if (expression.operator_ == "LE") {
    comparator = [&expression](auto frequency) {
      return frequency < expression.n_;
    };
  } else if (expression.operator_ == "GR") {
    comparator = [&expression](auto frequency) {
      return frequency > expression.n_;
    };
  } else {
    assert(false);
  }

  std::set<int> resulting_set;

  for (const auto& record : element2frequency) {
    if (comparator(record.second)) {
      resulting_set.insert(record.first);
    }
  }

  return resulting_set;
}

std::set<int> Calculator::operator()(const std::string& filename) {
  std::ifstream set_file(filename);
  if (!set_file.good()) {
    throw std::logic_error("Cannot open file " + filename);
  }

  std::set<int> elements;

  std::string line;
  while (std::getline(set_file, line)) {
    elements.insert(std::stoi(line));
  }

  return elements;
}
}  // namespace ast
