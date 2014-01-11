//個別トークン格納クラス

#ifndef __LEXER_TOKEN_HPP
#define __LEXER_TOKEN_HPP

#include "../APP.hpp"
#include "tokentype.hpp"


#include<stdio.h>

class Token {
	private:
	TokenType type;
	std::string tokenString;
	int number;
	int line;

	public:
	Token(std::string str, TokenType t, int l)
		: tokenString(str), type(t), line(l)
	{
		if(t == TOK_DIGIT)
			number = atoi(str.c_str());
		else
			number = INT_MAX;
	}
	
	~Token(){};

	//トークンの種別を取得
	TokenTypevgetTokenType() { return Type; };

	//トークンの文字列表現を取得
	std::string getTokenString() { return TokenString; };

	//トークンの数値を取得(数字である場合)
	int getNumberValue() { return Number; };

	//トークンの出現した行数
	int getLine() { return Line; };

};

#endif
