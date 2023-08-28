#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

template<class T>
class My_SharedPtr
{
public:
	My_SharedPtr()
	{

	}
	My_SharedPtr<T>(T* ptr)
	{
		m_ptr = ptr;
		m_count = new int(1);
	}

	My_SharedPtr(const My_SharedPtr<T>& tempShared)
	{
		m_ptr = tempShared.m_ptr;
		(*tempShared.m_count)++;
		m_count = tempShared.m_count;

	}

	My_SharedPtr& operator = (const My_SharedPtr<T>& tempShared)
	{
		if (this == &tempShared)
		{
			return *this;
		}

		(*m_count)--;
		if ((*m_count) == 0)
		{
			delete m_ptr;
			m_ptr = NULL;
		}
		m_ptr = tempShared.m_ptr;
		(*tempShared.m_count)++;
		m_count = tempShared.m_count;

		return *this;
	}

	~My_SharedPtr()
	{
		(*m_count)--;
		if ((*m_count) == 0)
		{
			delete m_ptr;
			m_ptr = NULL;
		}
	}

	T& operator * ()
	{
		return (*m_ptr);
	}

	T* operator -> ()
	{
		return m_ptr;
	}

private:
	T* m_ptr;
	int* m_count;

};
