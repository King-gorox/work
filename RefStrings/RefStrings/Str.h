#pragma once
#include "_str.h"
#include <ostream>
#include <iostream>
using namespace std;
class Str {
	_str* m_pStr;
public:
	Str() { m_pStr = new _str; }		//если не копия, то создаем
	Str(const char* p) {		// новый ресурс
		m_pStr = new _str(p);
	}
	~Str() {
		m_pStr->Release(); 	// Не уничтожаем ресурс!
	}				// Уменьшаем счетчик ссылок!

	int len() const {
		return strlen(m_pStr->m_pszData);
	}
	Str(const Str& s)
	{
		m_pStr = s.m_pStr; 	// ссылаемся на тот же ресурс
		m_pStr->AddRef(); 	// отмечаем, что сослались
	}
	//Присваивание образует выражение!
	Str& operator = (const Str& s) {
		if (this != &s) {
			s.m_pStr->AddRef(); // Важен порядок?!
			m_pStr->Release();
			m_pStr = s.m_pStr;
		}
		return *this;
	}
	///Операторы +=, []
	Str& operator += (const Str& s) {
		int length = len() + s.len();
		if (s.len() != 0) {		// добавление ничего не изменит!
			_str* pstrTmp = new _str; 	// Новый ресурс
			delete[] pstrTmp->m_pszData;

			pstrTmp->m_pszData = new char[length + 1];
			strcpy_s(pstrTmp->m_pszData, length + 1, m_pStr->m_pszData);
			strcat_s(pstrTmp->m_pszData, length + 1, s.m_pStr->m_pszData);

			m_pStr->Release();
			m_pStr = pstrTmp;
		}
		return *this;
	}
	
	operator const char* () const {
		return m_pStr->m_pszData;
	}
	int find(const char* t, int off) const {
		int lenT = strlen(t);
		int lenIS = len();
		bool flag = false;
		int temp;
		int j;
		char* a = m_pStr->m_pszData;
		if (lenT == 0) return -1;
		for (int i = off;i < lenIS; i++) {
			int tempI=i;
			temp = i;
			for (j = 0;j < lenT;j++) {
				cout << a[tempI]<<" "<<t[j]<< endl;
				if (a[tempI] != t[j]) break;
				else tempI++;
			}
			if (j == lenT) flag = true;
			if (flag) break;
		}
		if (!flag) return -1;
		return temp;
	}
};
