#include <iostream>
#include <string>
#include <boost/variant.hpp>

namespace ast
{
	struct integer;

	typedef boost::variant<
			integer,
			integer
		> literal;

	struct op_add;
	struct op_sub;

	template <class op> 
	struct formula;

	typedef boost::variant<
			literal,
			boost::recursive_wrapper< formula< op_add > >,
			boost::recursive_wrapper< formula< op_sub > >
		> expr;


	struct integer 
	{
		int value;
	};

	template <class op>
	struct formula
	{
		expr lhs, rhs;

		formula(expr const& lhs_, expr const& rhs_) :
			lhs( lhs_ ), rhs( rhs_ ) { }
	};

};
