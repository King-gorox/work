﻿
#include <iostream>
using namespace std;
int main()
{
    int a = 3, b = 5;
    Swap(a, b);
    cout << " После SWAP: a = " << a << " , b = " << b << endl;
    //int x = 3;
    //int* p = &x;
    //cout << x << ' ' << *p << p << endl;
    //p++;
    //cout << p << endl;
    //cout << p - &x << endl;
    //typedef unsigned char byte; 	// Нет встроенного byte
    //byte* pb = (byte*)--p;		// вернули указатель на x и преобразовали
    //for (byte* pt = pb; pt - pb < sizeof(int); pt++)
    //    cout << (int)*pt << ' ';	// выводим как int
    //cout << endl;


}
void Swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Swap(int* pa, int* pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}