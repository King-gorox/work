
#include <iostream>
using namespace std;

int main()
{
    int a[5]{ 1,2,3,4,5 };
    int size = sizeof(a) / sizeof(a[0]);
    rotate(a, size, true);
    for (int i = 0; i < size; i++)
        cout << a[i] << ' ';
    cout << endl;

    //for (int* p = a; p - a < 5; p++)
        //cout << *p << ' ';
    //for (int i = 0; i < 5; i++)
    // cout << a[i]; i << ' ';
    //cout << endl;

}

void rotate(int a[], int n, bool clockwise) 
{
    if (clockwise)
    {
        int x = a[n - 1];
        for (int i = n - 1; i > 0; i--) {
            a[i] = a[i-1];
        }
        a[0] = x;
    }
    else 
    {
        int x = a[0];
        for (int i = 0; i < n-1; i++) {
            a[i ] = a[i+1];
        }
        a[n - 1] = x;
    }
}


