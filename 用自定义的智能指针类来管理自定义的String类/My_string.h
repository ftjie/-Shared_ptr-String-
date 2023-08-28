#pragma once
#include <iostream>

using namespace std;

class My_string
{
public:
	My_string();
	My_string(char* str);
	My_string(const char* str);
	My_string(const My_string &str);
	~My_string();

	// 赋值运算符返回引用类型，减少拷贝构造函数的调用，优化性能；调用=的左侧对象，依旧是左侧对象，不是新构造的
	My_string& operator= (const My_string& str);


	//查看长度
	int m_Size();

	//查看指定位置字符
	char m_check(const int index);

	//判空
	bool isEmpty();

	//查看当前字符串,通过重载输出运算符来实现
	friend ostream& operator << (ostream& os, My_string& str);

	//通过重载输入运算符来实现
	friend istream& operator >> (istream& is, My_string& str);
	friend My_string operator + (My_string& str1, My_string& str2);
	friend My_string operator + (My_string& str1, char* str2);
	       
private:
	char* myStr;

};

