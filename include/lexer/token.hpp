//個別トークン格納クラス

#ifndef __LEXER_TOKEN_HPP
#define __LEXER_TOKEN_HPP

#include "../APP.hpp"
#include "tokentype.hpp"

#include<iostream>
#include<climits>

class Token {
	private:
	std::string tokenString;
	TokenType type;
	int number;
	int line;

	public:
	Token(std::string str, TokenType t, int l)
		: tokenString(str), type(t), line(l)
	{
		if(t == TOK_DIGIT)
			number = std::stoi(str);
		else
			number = INT_MAX;
	}
	
	~Token(){};

	//トークンの種別を取得
	TokenType getTokenType() { return type; };

	//トークンの文字列表現を取得
	std::string getTokenString() { return tokenString; };

	//トークンの数値を取得(数字である場合)
	int getNumberValue() { return number; };

	//トークンの出現した行数
	int getLine() { return line; };

};

#endif
