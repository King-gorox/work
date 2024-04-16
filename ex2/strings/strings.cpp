
#include <iostream>
#include <cstring>

int len(const char* s);
int compare(const char* s, const char* t);

void string_copy(char* d, const char* s) {
    while (*s) {
        *d = *s;
        d++;
        s++;
    }
    *d = '\0';
}

int main() {
    char str[] = "Hello!";
    char t[32];

    std::cout << str << std::endl;
    std::cout << len(str) << ' ' << sizeof(str) << std::endl;

    string_copy(t, str);
    std::cout << t << std::endl;

    std::cout << compare(str, t) << std::endl;

    return 0;
}

int len(const char* s) {
    int length = 0;
    while (*s != '\0') {
        length++;
        s++;
    }
    return length;
}

int compare(const char* s, const char* t) {
    while (*s && (*s == *t)) {
        s++;
        t++;
    }
    return *s - *t;
}