#include <iostream>
#include <initializer_list>
#include <numeric>
#include <iterator>

template <typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t list_size;

    void copyList(const SinglyLinkedList& other) {
        Node* current = other.head;
        while (current) {
            push_back(current->data);
            current = current->next;
        }
    }

    void clearList() {
        while (head) {
            pop_front();
        }
    }

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), list_size(0) {}

    SinglyLinkedList(const SinglyLinkedList& other) : head(nullptr), tail(nullptr), list_size(0) {
        copyList(other);
    }

    SinglyLinkedList& operator=(const SinglyLinkedList& other) {
        if (this != &other) {
            clearList();
            copyList(other);
        }
        return *this;
    }

    SinglyLinkedList(SinglyLinkedList&& other) noexcept
        : head(other.head), tail(other.tail), list_size(other.list_size) {
        other.head = nullptr;
        other.tail = nullptr;
        other.list_size = 0;
    }

    SinglyLinkedList& operator=(SinglyLinkedList&& other) noexcept {
        if (this != &other) {
            clearList();
            head = other.head;
            tail = other.tail;
            list_size = other.list_size;
            other.head = nullptr;
            other.tail = nullptr;
            other.list_size = 0;
        }
        return *this;
    }

    ~SinglyLinkedList() {
        clearList();
    }

    void push_back(const T& value) {
        Node* new_node = new Node(value);
        if (tail) {
            tail->next = new_node;
        }
        else {
            head = new_node;
        }
        tail = new_node;
        ++list_size;
    }

    void push_front(const T& value) {
        Node* new_node = new Node(value);
        if (!head) {
            tail = new_node;
        }
        new_node->next = head;
        head = new_node;
        ++list_size;
    }

    void insert(size_t idx, const T& value) {
        if (idx == 0) {
            push_front(value);
            return;
        }
        if (idx >= list_size) {
            push_back(value);
            return;
        }
        Node* new_node = new Node(value);
        Node* current = head;
        for (size_t i = 0; i < idx - 1; ++i) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        ++list_size;
    }

    void pop_back() {
        if (!head) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        --list_size;
    }

    void pop_front() {
        if (!head) return;
        Node* old_head = head;
        head = head->next;
        if (!head) {
            tail = nullptr;
        }
        delete old_head;
        --list_size;
    }

    void remove_at(size_t index) {
        if (index == 0) {
            pop_front();
            return;
        }
        if (index >= list_size) return;

        Node* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node* to_delete = current->next;
        current->next = to_delete->next;
        if (to_delete == tail) {
            tail = current;
        }
        delete to_delete;
        --list_size;
    }

    T& operator[](const size_t index) {
        Node* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    const T& operator[](const size_t index) const {
        Node* current = head;
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
        return head->data;
    }

    T back() const {
        return tail->data;
    }

    class ListIterator : public std::iterator<std::forward_iterator_tag, T> {
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

        ListIterator operator++(int) {
            ListIterator temp = *this;
            node = node->next;
            return temp;
        }

        bool operator==(const ListIterator& other) const {
            return node == other.node;
        }

        bool operator!=(const ListIterator& other) const {
            return node != other.node;
        }
    };

    ListIterator begin() {
        return ListIterator(head);
    }

    ListIterator end() {
        return ListIterator(nullptr);
    }

    SinglyLinkedList(std::initializer_list<T> ilist) : head(nullptr), tail(nullptr), list_size(0) {
        for (const T& item : ilist) {
            push_back(item);
        }
    }
};

int main() {
    setlocale(LC_ALL, "RU");
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