// KMP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PF.h"
#include <vector>
#include <set>
using namespace std;

unsigned SSCount(const char* s) {
	int n = strlen(s);
	set<string> substrings;
	for (int i = 0; i < n; ++i) {
		string tmp;
		for (int j = i + 1; j <= n; ++j) {
			tmp.push_back(s[j - 1]);
			substrings.insert(tmp);
		}
	}
	return substrings.size();
}


unsigned SimpleSSCount(const char* s) {
	string str(s);
	string* substrings = new string[str.length() * str.length()];
	int count = 0;
	for (int len = 1; len <= str.length(); len++) {
		for (int i = 0; i <= str.length() - len; i++) {
			string substr = str.substr(i, len);
			bool found = false;
			for (int j = 0; j < count; j++) {
				if (substrings[j] == substr) {
					found = true;
					break;
				}
			}
			if (!found) substrings[count++] = substr;
		}
	}
	delete[] substrings;
	return count;
}

int main()
{
	// ѕример использовани€ класса PF.
	char s[] = "ghfhgfghfhfhgfhfhgfhghghghgf";
	PF pf;
	pf.Init(s, strlen(s));
	cout << s << endl;
	for (int i = 0; i < pf; i++)
		cout << pf.pattern(i);
	cout << endl;
	for (int i = 0; i < pf; i++)
		cout << pf[i];
	cout << endl;

	// ѕример перебора всех подстрок s длины 8, использу€ класс string.
	cout << endl;
	string str(s);
	for (int i = 0; i < str.length() - 7; i++)
		cout << str.substr(i, 8) << endl;

	// ѕример генерации случайной строки длины N.
	cout << endl;
	const int N = 50;
	char t[N]{ 0 };
	for (int i = 0; i < N - 1; i++)
		t[i] = rand() % ('z' - 'a') + 'a';
	cout << t << endl;

	char a[] = "abcd";
	cout << SSCount(a) << endl;
	cout << SimpleSSCount(a) << endl;
	char str128[128]{ 0 };
	for (int j = 0; j < 127; j++) {
		str128[j] = rand() % ('z' - 'a') + 'a';
	}
	cout << SSCount(str128) << endl;
	cout << SimpleSSCount(str128) << endl;

	char str1024[1024]{ 0 };
	for (int k = 0; k < 1023; k++) {
		str1024[k] = rand() % ('z' - 'a') + 'a';
	}
	cout << SSCount(str1024);
	return 0;
}
