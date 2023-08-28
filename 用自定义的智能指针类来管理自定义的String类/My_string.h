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

	// ��ֵ����������������ͣ����ٿ������캯���ĵ��ã��Ż����ܣ�����=�������������������󣬲����¹����
	My_string& operator= (const My_string& str);


	//�鿴����
	int m_Size();

	//�鿴ָ��λ���ַ�
	char m_check(const int index);

	//�п�
	bool isEmpty();

	//�鿴��ǰ�ַ���,ͨ����������������ʵ��
	friend ostream& operator << (ostream& os, My_string& str);

	//ͨ�����������������ʵ��
	friend istream& operator >> (istream& is, My_string& str);
	friend My_string operator + (My_string& str1, My_string& str2);
	friend My_string operator + (My_string& str1, char* str2);
	       
private:
	char* myStr;

};

