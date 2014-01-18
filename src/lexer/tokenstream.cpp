#include "tokenstream.hpp"

#include<stdio.h>

//�ǥ��ȥ饯��
TokenStream::~TokenStream() {
	for(unsigned int i=0; i<Tokens.size(); i++) {
		SAFE_DELETE(Tokens[i]);
	}
	Tokens.clear();
}

/*
 * �ȡ��������
 * @return CureIndex���ܤ�Token
 */

Token TokenStream::getToken() {
	return *Tokens[CurIndex];
}

/*
 * ����ǥ����������䤷�Ƽ��Υȡ�����˿ʤ��
 * @return ����true
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
 * ����ǥå�����times���᤹
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
 * ��Ǽ���줿�ȡ����������ɽ������
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


