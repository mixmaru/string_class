#ifndef __STRING_HXX_INCLUDED__
#define  __STRING_HXX_INCLUDED__

class string{
private:
	char *str;
	int str_count;
	int max_char_num;
	int _length(const char *);
	
public:
	string();
	void set(const char *);
	void add(const char *);
	string extract(int, int);
	char *value();
	int length();
};

#endif
