#include <Test.hpp>
#include <iostream>

int main() {
    Test test = Test(5);
    std::cout << test.get_value() << std::endl;

    return 0;
}