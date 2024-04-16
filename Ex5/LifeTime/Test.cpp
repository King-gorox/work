#include "Test.h"
//#include <iostream>
//using namespace std;

int Test::nCount = 0;
int GlobalTest::nnCount = 0;

Test::Test()
{
	cout << "konstr" << endl;
	++nCount;// ���������� ��� ������ ������������
	cout << "count of objects: " << nCount << endl;
}

Test::~Test()
{
	cout << "destr" << endl;
	--nCount; //���������� ��� ������ �����������
	cout << "count of objects: " << nCount << endl;
}

GlobalTest::GlobalTest()
{
	cout << "GLOBAL konstr" << endl;
	++nnCount;// ���������� ��� ������ ������������
	cout << "(GLOBAL) count of objects: " << nnCount << endl;
}

GlobalTest::~GlobalTest()
{
	cout << "GLOBAL destr" << endl;
	--nnCount; //���������� ��� ������ �����������
	cout << "(GLOBAL) count of objects: " << nnCount << endl;
}

Test::Test(const Test& a)
{
	++nCount;
	cout << "Copying object" << endl;
}

void foo(Test t)
{
	cout << "foo is running" << endl;
}

Child::Child()
{
	cout << "Child created" << endl;
}

Child::~Child()
{
	cout << "Child deleted" << endl;
}

Aggregate::Aggregate()
{
	cout << "Aggregate created" << endl;
}
Aggregate::~Aggregate()
{
	cout << "Aggregate deleted" << endl;
}