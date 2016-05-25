#ifndef __STRING_HXX_INCLUDED__
#define  __STRING_HXX_INCLUDED__

class string{
private:
	char *m_str;//文字列を格納する
	int m_count;//格納された文字数を格納する
	int m_limit;//格納できる最大文字数を入れる。（確保メモリサイズ-1）
	void _expandLimit(int want_limit);//m_strのメモリサイズをwant_limit文字入るように拡張する
	int _length(const char *string);//文字列定数の文字数を返す
	void _add(char *string1, const char *string2);//string1の文字列の末尾からstring2の文字列を追加する
	
public:
	string();//コンストラクタ
	void set(const char *string);//文字列をセットする
	void add(const char *string);//文字列を追加する
	string extract(int start, int limit);//m_strからstart+1文字目からlimit文字を取り出した新しいstringインスタンスを返す
	char *value();//m_str文字列のポインタを返す
	int length();//m_countを返す
};

#endif
