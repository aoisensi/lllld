#include <iostream>
#include <string>
#include <boost/phoenix.hpp>
#define BOOST_SPIRIT_USE_PHOENIX_V3 1
#include <boost/spirit/include/qi.hpp>

#include "../include/ast.hpp"

namespace qi = boost::spirit::qi;
namespace phx = boost::phoenix;

namespace lexer
{

	template <class Iterator>
	struct grammar :
		qi::grammar< Iterator, ast::expr() >
	{

		template <typename T>
		using rule = qi::rule< Iterator, T >;

		rule< ast::integer() > integer;
		rule< ast::literal() > literal;

		grammar() :
			grammar::base_type( literal )
		{
			namespace phx = boost::phoenix;

			integer = qi::int_[qi::_val = phx::construct<ast::integer>(qi::_1)];
			literal = integer[qi::_val = phx::construct<ast::literal>(qi::_1)]; 

		}
	};
}
