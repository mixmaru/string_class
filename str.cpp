#include "str.hxx"
#include <stdio.h>

string::string(){
	str = new char[11];
	*str = 0;
	str_count = 0;
	max_char_num = 10;
}

void string::set(const char *arg_str){
	//必要ならメモリ領域を追加
	int need_count = _length(arg_str) + str_count;

	if(need_count > max_char_num){
		//必要な文字数の2倍のメモリ領域を確保(+1はhull文字分)
		max_char_num = (need_count * 2) + 1;
		str = new char[max_char_num];
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
}

void string::add(const char *str){

}

string string::extract(int start, int length){

	return string();
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
