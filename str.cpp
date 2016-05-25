#include "str.hpp"
#include <stdio.h>

string::string(){
	m_str = new char[11];
	*m_str = 0;
	m_count = 0;
	m_limit = 10;
}

void string::set(const char *arg_str){
	//必要ならメモリ領域を追加
	int add_count = _length(arg_str);
	int need_count = add_count + m_count;
	//メモリサイズが足りない場合はメモリ追加する
	if(need_count > m_limit){
		_expandLimit(need_count);
	}

	//文字をコピーする
	_add(m_str, arg_str);

	//文字カウント更新
	m_count = m_count + need_count;
}

void string::add(const char *arg_str){
	int add_count = _length(arg_str);
	int need_count = add_count + m_count;
	//メモリサイズが足りない場合はメモリ追加する
	if(need_count > m_limit){
		_expandLimit(need_count);
	}

	//m_strの末へ追加していく
	_add(m_str, arg_str);
	
	//文字数カウント更新
	m_count = m_count + add_count;
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
	return m_count;
}

int string::_length(const char *arg_str){
	int count = 0;
	while(*arg_str){
		arg_str++;
		count++;
	}
	return count;
}

void string::_expandLimit(int want_limit){
	//tmp_strに必要量の倍のメモリを確保する
	m_limit = want_limit * 2;
	char *tmp_str = new char[m_limit + 1];

	//m_strの文字をtmp_strに移す
	_add(tmp_str, m_str);
	
	delete[] m_str;
	m_str = tmp_str;
}

void string::_add(char *string1, const char *string2){
	//string1のポインタを、\0の位置まですすめる
	while(*string1){
		string1++;
	}
	//string1の\0の位置からstring2を追加する
	while(*string2){
		*string1 = *string2;
		string1++;
		string2++;
	}
	*string1 = '\0';
}
