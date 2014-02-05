#include <iostream>
#include <string>
#include <boost/variant.hpp>

using variant = boost::variant;

namespace ast
{

	struct integer;

	typedef variant<
		integer
			> literal;


}
