#include "tokenstream.hpp"

#include<stdio.h>

//デストラクタ
TokenStream::~TokenStream() {
	for(unsigned int i=0; i<Tokens.size(); i++) {
		SAFE_DELETE(Tokens[i]);
	}
	Tokens.clear();
}

/*
 * トークン取得
 * @return CureIndex番目のToken
 */

Token TokenStream::getToken() {
	return *Tokens[CurIndex];
}

/*
 * インデクスを一つ増やして次のトークンに進める
 * @return 成功true
 */

bool TokenStream::getNextToken() {
	int size = Tokens.size();
	if(--size <= CurIndex) {
		return false;
	} else {
		CurIndex++;
		return true;
	}
}

/*
 * インデックスをtimes回戻す
 */

bool TokenStream::ungetToken(int times) {
	for(int i=0; i<times; i++) {
		if(CurIndex == 0)
			return false;
		else
			CurIndex--;
	}
	return true;
}

/*
 * 格納されたトークン一覧を表示する
 */

bool TokenStream::printTokens() {
	std::vector<Token*>::iterator titer = Tokens.begin();
	while( titer != Tokens.end() ) {
		fprintf(stdout, "%d:", (*titer) -> getTokenType());
		if((*titer) -> getTokenType() != TOK_EOF)
			fprintf(stdout, "%s\n", (*titer) -> getTokenString().c_str());
		++titer;
	}
	return true;
}


