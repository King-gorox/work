#pragma once
#include <iostream>
using namespace std;
class Test
{
public:
	Test(); //������

	Test(const Test& a); //"���������" ����������� �����������

	~Test(); // ����������
	static int nCount; //���������� ��������� ��������
};

class GlobalTest
{
public:
	GlobalTest();
	~GlobalTest();
	static int nnCount;
};

void foo(Test t);

class Child : public Test
{
public:
	Child();
	~Child();
};

class Aggregate
{
public:
	Test m_objTest;
	Aggregate();
	~Aggregate();
};

//�����-������(������������� � ������������ �����)
template <class T> class AggregateT
{
public:
	T m_objTest;
	AggregateT()
	{
		cout << "AggregateT constr" << endl;
	}
	~AggregateT()
	{
		cout << "AggregateT destr" << endl;
	}
};
