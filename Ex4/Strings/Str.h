#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
class Str
{
private:
	char* m_pszText;
public:
	Str() 	//����������� ��� ���������� (default)*
	{
		m_pszText = new char[1] {0};
	}

	~Str() { delete[]m_pszText; } //���������� ����������!!!!!!

	//����������� ������������� ��� ������
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


	//����������� �����������
	Str(const Str& s) //����������� ������ �� ������
	{
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText,
			strlen(s.m_pszText) + 1,
			s.m_pszText);
	}

	//�������� ������������ = 
	const Str& operator = (const Str& s) //����������� ������ �� ������
	{
		if (&s == this) return *this;
		delete[] m_pszText;	 //����������� ������� ������					
		//������ ������ �����������
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText,
			strlen(s.m_pszText) + 1,
			s.m_pszText);
		return *this;
	}
	//�������� += ������� ��������� ������ � ����� ������� ������ 
	Str& operator +=(const char* sz) 
	{
		size_t nwLen = strlen(m_pszText) + strlen(sz); //����� ����� ������

		char* t = new char[strlen(m_pszText) + strlen(sz) + 1]; //�������� ������ ��� ���������� �������
		
		strcpy(t, m_pszText); //����� ������� ������ � ������
		strcpy(t + strlen(m_pszText), sz); //�����  ������ � �������
		//strcat(t)
		
		delete[] m_pszText; //������� ������ ������

		m_pszText = t; //��������� ��� ��� ����� ������ 
		
		return *this;
	}

	//�������� + ������� �������� ����� ������ ������ ����� ���� �����
	Str operator +(const char* sz) const 
	{
		Str r(m_pszText); //����� ������� �������

		r += sz; //��������� ������ � �����

		return r;
	}

};

