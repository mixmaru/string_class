#ifndef __STRING_HXX_INCLUDED__
#define  __STRING_HXX_INCLUDED__

class string{
private:
	char *m_str;//文字列を格納する
	int m_count;//格納された文字数を格納する
	int m_limit;//格納できる最大文字数を入れる。（確保メモリサイズ-1）

	//m_strのメモリサイズをwant_limit文字入るように拡張する
	void _expandLimit(int want_limit);

	//文字列定数の文字数を返す
	int _length(const char *string);

	//string1の文字列の末尾からstring2の文字列を追加する
	void _add(char *string1, const char *string2);

	//from_strのstart文字目からlength文字をto_strへコピーする
	void _extract(const char *from_str, char *to_str, int start, int length);
	
public:
	string();//コンストラクタ
	~string();//デストラクタ

	//文字列をセットする
	void set(const char *string);

	//文字列を追加する
	void add(const char *string);

	//m_strからstart+1文字目からlimit文字を取り出した新しいstringインスタンスを返す
	string extract(int start, int limit);

	//m_str文字列のポインタを返す
	char *value();

	//m_countを返す
	int length();
};

#endif
