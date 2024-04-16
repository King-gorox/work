#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
public:
    double Re;  // ƒействительна€ часть
    double Im;  // ћнима€ часть

    //  онструктор с инициализацией Re и Im
    Complex(double re = 0, double im = 0) : Re(re), Im(im) {}

    //+
    Complex operator+(const Complex& c) const 
    {
        return Complex(Re + c.Re, Im + c.Im);
    }
    //-
    Complex operator-(const Complex& c) const
    {
        return Complex(Re - c.Re, Im - c.Im);
    }
    //*
    Complex operator*(const Complex& c) const
    {
        return Complex(Re * c.Re - Im * c.Im, Re * c.Im + Im * c.Re);
    }
    // деление
    Complex operator/(const Complex& c) const
    {
        return Complex((Re * c.Re + Im * c.Im) / (c.Re * c.Re + c.Im * c.Im),
            (-Re * c.Im + c.Re * Im) / (c.Re * c.Re + c.Im * c.Im));
    }
    //метод сопражени€ числа
    Complex Conjugate() const
    {
        return Complex(Re, -Im);
    }

    //метод, возвращающий модуль комплексного числа
    double Mod() const
    {
        return sqrt(Re * Re + Im * Im);
    }

    //метод, возвращающий аргумент комплексного числа в экспоненциальном представлении
    double Arg() const
    {
        if (Mod() == 0)
            return 0;
        else if (Re > 0)
            return atan(Im / Re);
        else if (Re < 0)
        {
            if (Im >= 0)
            {
                return acos(-1) + atan(Im / Re);
            }
            else
            {
                return -acos(-1) - atan(Im / Re);
            }
        }
        else
        {
            if (Im > 0)
            {
                return acos(0);
            }
            else
            {
                return -acos(0);
            }
        }
    }
};
inline ostream& operator << (ostream& o, const Complex& c) { return o << '(' << c.Re << ", " << c.Im << ')'; }