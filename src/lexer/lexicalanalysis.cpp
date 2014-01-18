#include "lexer.hpp"

#include<stdio.h>

/*
 * トークン切り出し関数i
 * @param 字句解析対象ファイル名
 * @return 切り出したトークンを格納したTokenStream
 */

TokenStream* LexicalAnalysis(std::string input_filename) {
	TokenStream* tokens = new TokenStream();
	std::ifstream ifs;
	std::string cur_line;
	std::string token_str;
	int line_num = 0;
	bool iscomment = false;

	ifs.open(input_filename.c_str(), std::ios::in);
	if(!ifs)
		return NULL; //エラー落ち
	while(ifs && getline(ifs, cur_line) { //一行読み込む
		char next_char;
		std::string line;
		Token* next_token;
		int index = 0;
		int length = cur_line.length();
		
		while(index < length) { //一文字づつ読み込む
			next_char = cur_line.at(index++);

			//コメント読み飛ばし
			if(iscomment) {
				if((length - index) < 2 
				|| (cur_line.at(index) != '*'
				|| (cur_line.at(index++) != '/') ) {
					continue;
				} else {
					iscomment = false;
				}
			}

			//EOF ファイルの終わりかどうか
			if(next_char == EOF) {
				token_str = EOF;
				next_token = new Token(token_str, TOK_EOF, line_num);

			adfsafdsa
			}
		}
	}

}
