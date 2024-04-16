#pragma once
#include <iostream>
using namespace std;
class Test
{
public:
	Test(); //констр

	Test(const Test& a); //"говорящий" конструктор копирования

	~Test(); // деструктор
	static int nCount; //количество созданных объектов
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

//класс-шаблон(располагается в заголовочном файле)
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
