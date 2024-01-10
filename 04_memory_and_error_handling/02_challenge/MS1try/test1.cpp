#include <iostream>

const int global_var = 3;

int& complex_function(int*& a, int*& b, int& c) {
    int* temp = a;
    a = b;
    b = temp;
    c = *a + *b;
    return global_var;
}

int main() {
    int x = 1;
    int y = 2;
    int* p1 = &x;
    int* p2 = &y;
    int result = 0;
    int& ref = complex_function(p1, p2, result);

    std::cout << "x: " << x << ", y: " << y << ", *p1: " << *p1 << ", *p2: " << *p2
              << ", result: " << result << ", ref: " << ref << ", global_var: " << global_var << std::endl;

    ref = 10;

    std::cout << "x: " << x << ", y: " << y << ", *p1: " << *p1 << ", *p2: " << *p2
              << ", result: " << result << ", ref: " << ref << ", global_var: " << global_var << std::endl;

    return 0;
}