//トークン種別

#ifndef __LEXER_TOKENTYPE_HPP
#define __LEXER_TOKENTYPE_HPP

#include "../APP.hpp"

enum TokenType {
	TOK_INDENTIFIER,
	TOK_DIGIT,
	TOK_SYMBOL,
	TOK_INT,
	TOK_RETURN,
	TOK_EOF
};

#endif
