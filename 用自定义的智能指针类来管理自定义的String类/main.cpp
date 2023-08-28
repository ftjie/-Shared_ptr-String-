#include "My_string.h"
#include "My_SharedPtr.h"

#include <iostream>
#include <algorithm>
#include <utility> // std::move() º¯Êý

using namespace std;

int main()
{
	My_SharedPtr<My_string> temp = My_SharedPtr<My_string>(new My_string("asd"));

	cout << (*temp) << endl;

	return 0;
}