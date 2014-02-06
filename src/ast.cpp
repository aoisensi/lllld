#include <iostream>
#include <string>
#include <boost/variant.hpp>

namespace ast
{
	struct integer;
	typedef boost::variant<
		integer
			> literal;
	
	typedef boost::variant<
		literal
			> valavl;

	struct integer 
	{
		int value;
	};

}
