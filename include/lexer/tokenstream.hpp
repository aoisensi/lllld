//切り出したトークン格納用クラス

#ifndef __LEXER_TOKENSTREAM_HPP
#define __LEXER_TOKENSTREAM_HPP

#include "../APP.hpp"
#include "tokentype.hpp"
#include "token.hpp"

#include<stdio.h>

class TokenStream {
	private:
		std::vector<Token*> Tokens;
		int CurIndex;

		Token* getCurToken() { return Tokens[CurIndex]; };

	public:
		TokenStream() : CurIndex(0) {}
		~TokenStream();

		bool ungetToken(int Times=1);
		bool getNextToken();
		bool pushToken(Token* token) {
			Tokens.push_back(token);
			return true;
		}
		Token getToken();

		//トークンの種類を取得
		TokenType getCurType() { return getCurToken() -> getTokenType(); }

		//トークンの文字列表現を取得
		std::string getCurString() { return getCurToken() -> getTokenString(); };

		//トークンの数値を取得
		int getCurNumVal() { return getCurToken() -> getNumberValue(); };

		//インデックスを指定した値に設定
		bool applyTokenIndex(int index) {
			CurIndex = index;
			return true;
		};

		bool printTokens();
}

#endif
