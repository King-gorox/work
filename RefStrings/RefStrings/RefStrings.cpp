#include <iostream>
#include <locale>
#include "Str.h"
#define _CRT_SECURE_NO_WARNINGS 
using namespace std;
int main()
{
	setlocale(LC_ALL, "RU");
	Str s = "Hello";
	cout << s<< endl;
	Str k = "world";
	s += k;
	cout << "Проверка" << " " << s.find("Hello", 0) << endl;
	cout <<"Проверка на пустой"<<" "<< s.find("", 0) << endl;
	cout <<"Проверка параметра off"<<" "<< s.find("world", 20) << endl;
	cout << "искомый образец совпадает с окончанием исходной строки" << " " << s.find("world", 1) << endl;
}

