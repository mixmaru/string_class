#ifndef __STRING_HXX_INCLUDED__
#define  __STRING_HXX_INCLUDED__

class string{
private:
	char *m_str;
	int m_count;
	int m_limit;
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
