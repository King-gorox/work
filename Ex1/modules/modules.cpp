#include <iostream>

using namespace std;

int Plus(int a, int b); // прототип функции plus

int main() 
{
    int x = 3, y = 5;
    cout << x + y << endl; 

    cout << Plus(x, y) << endl; // Вызов функции Plus и вывод результата

    return 0;
}

int Plus(int a, int b) 
{
    return a + b;
}