#include <Test.hpp>

Test::Test() {
    _value = 0;
}
    
Test::Test(int value) {
    _value = value;
}

int Test::get_value() { return _value; }