#include "str.hpp"
#include <stdio.h>

string::string(){
	str = new char[11];
	*str = 0;
	str_count = 0;
	max_char_num = 10;
}

void string::set(const char *arg_str){
	//必要ならメモリ領域を追加
	int add_count = _length(arg_str);
	int need_count = add_count + str_count;

	if(need_count > max_char_num){
		//必要な文字数の2倍のメモリ領域を確保(+1はhull文字分)
		max_char_num = (need_count * 2);
		str = new char[max_char_num + 1];
		*str = 0;
	}

	//文字をコピーする
	char *work_str = str;
	const char *work_arg_str = arg_str;
	while(*work_arg_str){
		*work_str = *work_arg_str;
		work_str++;
		work_arg_str++;
	}
	*work_str = '\0';

	//文字カウント更新
	str_count = str_count + need_count;
}

void string::add(const char *arg_str){
	int add_count = _length(arg_str);
	int need_count = add_count + str_count;
	if(need_count > max_char_num){
		//tmp_strに必要量の倍のメモリを確保する
		max_char_num = need_count * 2;
		char *tmp_str = new char[max_char_num + 1];

		//strの文字をtmp_strに移す
		char *work_str = str;
		char *work_tmp_str = tmp_str;
		while(*work_str){
			*work_tmp_str = *work_str;
			work_tmp_str++;
			work_str++;
		}
		*work_tmp_str = '\0';
		
		str = tmp_str;
	}

	//strの末へ追加していく
	char *work_str = str + str_count;
	const char *work_arg_str = arg_str;
	while(*work_arg_str != '\0'){
		*work_str = *work_arg_str;
		work_str++;
		work_arg_str++;
	}
	*work_str = '\0';
	
	//文字数カウント更新
	str_count = str_count + add_count;
}

string string::extract(int start, int length){
	//strから文字を切り出す
	char *new_str = new char[length + 1];
	char *work_str = str + start;
	char *work_new_str = new_str;
	int i;
	for(i=0; i<length; i++){
		*(work_new_str+i) = *(work_str+i);
	}
	*(work_new_str+i) = '\0';

	//stringインスタンスとして作って返す
	string ret_string;
	ret_string.set(new_str);
	return ret_string;
}

char *string::value(){
	return str;
}

int string::length(){
	return str_count;
}

int string::_length(const char *arg_str){
	int count = 0;
	while(*arg_str){
		arg_str++;
		count++;
	}
	return count;
}
