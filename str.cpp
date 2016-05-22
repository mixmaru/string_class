#include "str.hpp"
#include <stdio.h>

string::string(){
	m_str = new char[11];
	*m_str = 0;
	m_str_count = 0;
	m_max_char_num = 10;
}

void string::set(const char *arg_str){
	//必要ならメモリ領域を追加
	int add_count = _length(arg_str);
	int need_count = add_count + m_str_count;

	if(need_count > m_max_char_num){
		//必要な文字数の2倍のメモリ領域を確保(+1はhull文字分)
		m_max_char_num = (need_count * 2);
		m_str = new char[m_max_char_num + 1];
		*m_str = 0;
	}

	//文字をコピーする
	char *work_str = m_str;
	const char *work_arg_str = arg_str;
	while(*work_arg_str){
		*work_str = *work_arg_str;
		work_str++;
		work_arg_str++;
	}
	*work_str = '\0';

	//文字カウント更新
	m_str_count = m_str_count + need_count;
}

void string::add(const char *arg_str){
	int add_count = _length(arg_str);
	int need_count = add_count + m_str_count;
	if(need_count > m_max_char_num){
		//tmp_strに必要量の倍のメモリを確保する
		m_max_char_num = need_count * 2;
		char *tmp_str = new char[m_max_char_num + 1];

		//m_strの文字をtmp_strに移す
		char *work_str = m_str;
		char *work_tmp_str = tmp_str;
		while(*work_str){
			*work_tmp_str = *work_str;
			work_tmp_str++;
			work_str++;
		}
		*work_tmp_str = '\0';
		
		m_str = tmp_str;
	}

	//m_strの末へ追加していく
	char *work_str = m_str + m_str_count;
	const char *work_arg_str = arg_str;
	while(*work_arg_str != '\0'){
		*work_str = *work_arg_str;
		work_str++;
		work_arg_str++;
	}
	*work_str = '\0';
	
	//文字数カウント更新
	m_str_count = m_str_count + add_count;
}

string string::extract(int start, int length){
	//m_strから文字を切り出す
	char *new_str = new char[length + 1];
	char *work_str = m_str + start;
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
	return m_str;
}

int string::length(){
	return m_str_count;
}

int string::_length(const char *arg_str){
	int count = 0;
	while(*arg_str){
		arg_str++;
		count++;
	}
	return count;
}
