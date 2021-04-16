#include "parser_def.h"

namespace parser {
namespace x3 = boost::spirit::x3;

BOOST_SPIRIT_INSTANTIATE(ExpressionType, std::string::const_iterator,
                         x3::phrase_parse_context<x3::ascii::space_type>::type);
}  // namespace parser
