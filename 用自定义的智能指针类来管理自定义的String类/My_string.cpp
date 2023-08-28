#include "My_string.h"


using namespace std;

My_string::My_string()
{
	myStr = new char[100];

}

My_string::My_string(char* str)
{
	int len = 0;
	while (str[len]) { len++; }
	//cout << len << endl;

	myStr = new char[len + 1];
	for (int i = 0; i < len; i++) { myStr[i] = str[i]; }
	myStr[len] = '\0';
	cout << myStr << endl;
	//delete[]myStr;
}

My_string::My_string(const char* str)
{
	int len = 0;
	while (str[len]){len++;}

	myStr = new char[len+1];
	for (int i = 0; i < len; i++){myStr[i] = str[i];}
	myStr[len] = '\0';
}

My_string::My_string(const My_string& str)
{
	this->myStr = str.myStr;
	
}

My_string::~My_string()
{
	if (myStr != NULL)
	{
		//myStr = new char[3];
		//delete []myStr;
		//cout << "ÒÑ¾­Îö¹¹" << endl;
		myStr = NULL;
	}

}

My_string& My_string::operator = (const My_string& str)
{
	this->myStr = str.myStr;
	return *this;
}

int My_string::m_Size()
{
	int len = 0;
	while (myStr[len])
	{
		len++;
	}
	return len;
}

char My_string::m_check(int index)
{
	int len = 0;
	while (myStr[len]) { len++; }
	
	return myStr[index];
}

bool My_string::isEmpty()
{
	int len = 0;
	while (myStr[len])len++;
	if (len == 0)return true;
	else return false;

}

ostream& operator << (ostream& os, My_string& str)
{
	//str.m_print();
	os << str.myStr;
	return os;
}

istream& operator >> (istream& is, My_string& str)
{
	is >> str.myStr;

	return is;
}

My_string operator+ (My_string& str1, My_string& str2)
{
	//char *temp = (char*)malloc();
	char* temp = new char[str1.m_Size() + str2.m_Size()+1];
	//cout << str1 << "--xxx--" << str2 << endl;
	int index = 0;
	for (int i = 0; i < str1.m_Size(); i++, index++)
	{
		temp[index] = str1.m_check(i);
	}
	for (int i = 0; i < str2.m_Size(); i++, index++)
	{
		temp[index] = str2.m_check(i);
	}

	temp[index] = '\0';

	const char* temp2 = temp;

	My_string str(temp2);

	return str;
}

My_string operator + (My_string& str1, char* str2)
{
	//cout << str1 << "  xxxxx  " << str2 << endl;
	int str2Len = 0;
	while (str2[str2Len]) { str2Len++; }
	char* temp = new char[str1.m_Size() + str2Len + 1];

	int index = 0;
	temp[0] = str1.m_check(0);
	for (int i = 0; i < str1.m_Size(); i++, index++)
	{
		temp[index] = str1.m_check(i);
	}
	
	for (int i = 0; i < str2Len; i++,index++)
	{
		temp[index] = str2[i];
	}
	temp[index] = '\0';

	My_string str(temp);
	return str;
}