#include <iostream>
#include <initializer_list>
#include <numeric>
#include <iterator>
#include <stdexcept>

template <typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value, Node* next = nullptr) : data(value), next(next) {}
    };

    Node* head; // служебный узел
    size_t list_size;

    void copyList(const SinglyLinkedList& other) {
        clear();
        for (Node* current = other.head->next; current != other.head; current = current->next) {
            push_back(current->data);
        }
    }

    void clearList() {
        while (!empty()) {
            pop_front();
        }
    }

public:
    SinglyLinkedList() : head(new Node(T())), list_size(0) {
        head->next = head;
    }

    SinglyLinkedList(const SinglyLinkedList& other) : SinglyLinkedList() {
        copyList(other);
    }

    SinglyLinkedList& operator=(const SinglyLinkedList& other) {
        if (this != &other) {
            copyList(other);
        }
        return *this;
    }

    SinglyLinkedList(SinglyLinkedList&& other) noexcept
        : head(other.head), list_size(other.list_size) {
        other.head = new Node(T());
        other.head->next = other.head;
        other.list_size = 0;
    }

    SinglyLinkedList& operator=(SinglyLinkedList&& other) noexcept {
        if (this != &other) {
            clearList();
            delete head;
            head = other.head;
            list_size = other.list_size;
            other.head = new Node(T());
            other.head->next = other.head;
            other.list_size = 0;
        }
        return *this;
    }

    ~SinglyLinkedList() {
        clearList();
        delete head;
    }

    void push_back(const T& value) {
        Node* new_node = new Node(value, head);
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = new_node;
        ++list_size;
    }

    void push_front(const T& value) {
        Node* new_node = new Node(value, head->next);
        head->next = new_node;
        ++list_size;
    }

    void insert(size_t idx, const T& value) {
        if (idx > list_size) throw std::out_of_range("Index out of range");
        Node* current = head;
        for (size_t i = 0; i < idx; ++i) {
            current = current->next;
        }
        Node* new_node = new Node(value, current->next);
        current->next = new_node;
        ++list_size;
    }

    void pop_back() {
        if (empty()) throw std::out_of_range("List is empty");
        Node* current = head;
        while (current->next->next != head) {
            current = current->next;
        }
        delete current->next;
        current->next = head;
        --list_size;
    }

    void pop_front() {
        if (empty()) throw std::out_of_range("List is empty");
        Node* to_delete = head->next;
        head->next = head->next->next;
        delete to_delete;
        --list_size;
    }

    void remove_at(size_t index) {
        if (index >= list_size) throw std::out_of_range("Index out of range");
        Node* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        Node* to_delete = current->next;
        current->next = to_delete->next;
        delete to_delete;
        --list_size;
    }

    T& operator[](const size_t index) {
        if (index >= list_size) throw std::out_of_range("Index out of range");
        Node* current = head->next;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    const T& operator[](const size_t index) const {
        if (index >= list_size) throw std::out_of_range("Index out of range");
        Node* current = head->next;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    size_t size() const {
        return list_size;
    }

    bool empty() const {
        return list_size == 0;
    }

    void clear() {
        clearList();
    }

    T front() const {
        if (empty()) throw std::out_of_range("List is empty");
        return head->next->data;
    }

    T back() const {
        if (empty()) throw std::out_of_range("List is empty");
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        return current->data;
    }

    class ListIterator {
    private:
        Node* node;
    public:
        ListIterator(Node* node) : node(node) {}

        T& operator*() const {
            return node->data;
        }

        ListIterator& operator++() {
            node = node->next;
            return *this;
        }

        bool operator!=(const ListIterator& other) const {
            return node != other.node;
        }
    };

    ListIterator begin() {
        return ListIterator(head->next);
    }

    ListIterator end() {
        return ListIterator(head);
    }

    SinglyLinkedList(std::initializer_list<T> ilist) : SinglyLinkedList() {
        for (const T& item : ilist) {
            push_back(item);
        }
    }
};

int main() {
    SinglyLinkedList<int> l = { 3, 5, 2, 7, 8 };
    int s = 0;
    for (auto& i : l) s += i * 10;
    auto lambda = [](int a, int b) { return a + b * 10; };
    std::cout << s << '\t' << std::accumulate(l.begin(), l.end(), 0, lambda) << '\n';

    for (auto& value : l) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    l.push_front(9);
    l.push_back(1);

    l.remove_at(3);

    std::cout << "Элемент на индексе 3: " << l[3] << std::endl;
    for (auto& value : l) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}