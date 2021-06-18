#include <string>

enum MyEnum { EFirstEntry = 1, ESecondEntry };

std::string test_function1() {
    return "test_function()";
}

std::string test_function2(MyEnum k) {
    return "test_function(enum=" + std::to_string(k) + ")";
}

std::string test_function3(int i) {
    return "test_function(" + std::to_string(i) + ")";
}

std::string test_function4()           { return "test_function()"; }
std::string test_function4(char *)     { return "test_function(char *)"; }
std::string test_function4(int, float) { return "test_function(int, float)"; }
std::string test_function4(float, int) { return "test_function(float, int)"; }
