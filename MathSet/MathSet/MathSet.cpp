#include <iostream>
#include <set>
#include <unordered_set>
#include <cstdlib>
#include <ctime>
#include <algorithm>

template <typename T>
void printSet(const T& s) {
    for (const auto& elem : s) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

template <typename T>
T operator+(const T& lhs, const T& rhs) {
    T result(lhs);
    for (const auto& elem : rhs) {
        result.insert(elem);
    }
    return result;
}

template <typename T>
T operator*(const T& lhs, const T& rhs) {
    T result;
    for (const auto& elem : lhs) {
        if (rhs.find(elem) != rhs.end()) {
            result.insert(elem);
        }
    }
    return result;
}

int main() {
    std::unordered_set<int> set1, set2;

    std::srand(std::time(0));
    for (int i = 0; i < 15; ++i) {
        set1.insert(std::rand() % 100);
        set2.insert(std::rand() % 100);
    }

    std::cout << "Set1: ";
    printSet(set1);
    std::cout << "Set2: ";
    printSet(set2);

    std::unordered_set<int> set_union = set1 + set2;
    std::unordered_set<int> set_intersection = set1 * set2;

    std::cout << "Union: ";
    printSet(set_union);
    std::cout << "Intersection: ";
    printSet(set_intersection);

    return 0;
}