// LifeTime.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Test.h";
using namespace std;

GlobalTest globalTest;// объявление глобальный объект Test
int main()
{
    Test* p = new Test; //создание динамического объекта
    cout << "dinamic object created" << endl;

    Test* m = new Test[5]; //динамич. массив 
    cout << "dinamic mas created" << endl;

    Test test1; //копирование
    Test test2 = test1;

    foo(test2);

    int x;
    cout << "enter a number:  "; 
    cin >> x;
    cout << "the entered number: " << x << endl;

    cout << "Before creation of the object " << endl; //до создания
    Test test; //создание объекта
    Child child; 
    Aggregate aggregate;

    AggregateT<Test> aggregateTest;
    AggregateT<Child> aggregateChild;



    cout << "After creation of the object" << endl; //после создания

    cout << "Before destruction of the object " << endl; //до уничтожения
    
    cout << "After destruction of the object " << endl; //после уничтожения

    
    delete p;//удаление динам.объекта(освобождение памяти)
    cout << "dinamic object deleted" << endl;

    delete[] m;
    cout << "dinamic mas deleted" << endl;
    return 0;
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
