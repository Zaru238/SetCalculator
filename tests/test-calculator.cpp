#include <gtest/gtest.h>

#include <library/calculator.h>

TEST(CalculatorTest, SimpleEqual) {
  const std::string command = "[EQ 1 a.txt]";

  const auto resulting_set = calculate(command);

  ASSERT_EQ(resulting_set, (std::set<int>{1, 2, 3}));
}

TEST(CalculatorTest, SimpleGreater) {
  const std::string command = "[GR 1 a.txt]";

  const auto resulting_set = calculate(command);

  ASSERT_EQ(resulting_set, (std::set<int>{}));
}

TEST(CalculatorTest, SimpleLess) {
  const std::string command = "[LE 2 a.txt]";

  const auto resulting_set = calculate(command);

  ASSERT_EQ(resulting_set, (std::set<int>{1, 2, 3}));
}

TEST(CalculatorTest, FirstRequirementExample) {
  const std::string command = "[GR 1 c.txt [EQ 3 a.txt a.txt b.txt]]";

  const auto resulting_set = calculate(command);

  ASSERT_EQ(resulting_set, (std::set<int>{2, 3}));
}

TEST(CalculatorTest, SecondRequirementExample) {
  const std::string command = "[LE 2 a.txt [GR 1 b.txt c.txt]]";

  const auto resulting_set = calculate(command);

  ASSERT_EQ(resulting_set, (std::set<int>{1, 4}));
}
