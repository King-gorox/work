#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
class Str
{
private:
	char* m_pszText;
public:
	Str() 	//Конструктор “по умолчанию” (default)*
	{
		m_pszText = new char[1] {0};
	}

	~Str() { delete[]m_pszText; } //деструктор обязателен!!!!!!

	//конструктор инициализации для строки
	Str(const char* p)
	{
		if (p) {
			m_pszText = new char[strlen(p) + 1];
			strcpy_s(m_pszText, strlen(p) + 1, p);
		}
		else
			m_pszText = new char[1] {0};
	}
	operator const char* () const { return m_pszText; }


	//конструктор копирования
	Str(const Str& s) //Константная ссылка на объект
	{
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText,
			strlen(s.m_pszText) + 1,
			s.m_pszText);
	}

	//оператор присваивания = 
	const Str& operator = (const Str& s) //Константная ссылка на объект
	{
		if (&s == this) return *this;
		delete[] m_pszText;	 //Освобождаем текущие данные					
		//Дальше просто копирование
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText,
			strlen(s.m_pszText) + 1,
			s.m_pszText);
		return *this;
	}
	//оператор += который добавляет строку в конец текущей строки 
	Str& operator +=(const char* sz) 
	{
		size_t nwLen = strlen(m_pszText) + strlen(sz); //длина новой строки

		char* t = new char[strlen(m_pszText) + strlen(sz) + 1]; //выделяем память для совместной строчки
		
		strcpy(t, m_pszText); //копия текущей строки в память
		strcpy(t + strlen(m_pszText), sz); //копия  строки в текущую
		//strcat(t)
		
		delete[] m_pszText; //удаляем старую память

		m_pszText = t; //указываем что эта новая память 
		
		return *this;
	}

	//оператор + который получает новый объект равный сумме двух строк
	Str operator +(const char* sz) const 
	{
		Str r(m_pszText); //копия текущей стироки

		r += sz; //добавляем строку к копии

		return r;
	}

};

