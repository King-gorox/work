// classes.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include "Complex.h"
using namespace std;
int main()
{
	Complex *pc;
	Complex a(1, 2), b = 3;
	cout << a << ", " << b << endl;

	//pc = new Complex(1); //один параметр
	//pc = new Complex; //по умолчанию
	pc = new Complex(1, 2); //объект (1,2)
	cout << "Complex number = " << pc << endl;

	cout << "Complex number RE = " << pc-> Re << endl;
	cout << "Complex number IM = " << pc-> Im << endl;
	delete pc;

	Complex* m = new Complex[3];
	//pc[1].Re- это 2 элемент или же 2ое комплексное число Re ( действ. части)
	delete[] m;

	cout << "a + b = " << a + b << endl;
	cout << "a - b = " << a - b << endl;
	cout << "a * b = " << a * b << endl;
	cout << "a / b = " << a / b << endl;
	Complex summa = a + b;
	Complex minus = a - b;
	Complex umn = a * b;
	Complex del = a / b;
	cout << "summa - b = " << summa - b << endl;
	cout << "minus / b = " << minus / b << endl;

	cout << "conjugate a = " << a.Conjugate() << endl;

	cout << "Modul a = " << a.Mod() << endl;
	cout << "Argument a = " << a.Arg() << endl;

	Complex v[4]{ 1,2,Complex(2,3) };
	for (int i = 0; i < 4; i++)
	{
		cout << v[i] << ' ';
	}
	cout << endl;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
