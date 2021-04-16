#pragma once

#include <boost/fusion/include/adapt_struct.hpp>

#include "ast.h"

BOOST_FUSION_ADAPT_STRUCT(ast::Expression, operator_, n_, sets_)
