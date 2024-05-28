#include <iostream>
#include <memory>

class Test {
public:
    Test() { std::cout << "Test constructor" << std::endl; }
    ~Test() { std::cout << "Test destructor" << std::endl; }
};

int main() {
    {
        std::shared_ptr<Test> sp = std::make_shared<Test>();
        std::cout << "use_count: " << sp.use_count() << std::endl;

        std::weak_ptr<Test> wp = sp;
        std::cout << "use_count: " << sp.use_count() << std::endl;

        auto p = wp.lock();
        if (p) {
            std::cout << "object is alive, use_count: " << p.use_count() << std::endl;
        }
        else {
            std::cout << "no owing object" << std::endl;
        }
    }

    std::weak_ptr<Test> wp;
    auto p = wp.lock();
    if (p) {
        std::cout << "object is alive, use_count: " << p.use_count() << std::endl;
    }
    else {
        std::cout << "no owing object" << std::endl;
    }

    return 0;
}