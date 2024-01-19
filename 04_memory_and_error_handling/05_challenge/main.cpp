//# チャレンジ5
//次のコードの出力はどのようになりますか。必要に応じて、cppreference.comにある `std::vector` のドキュメントを参照してください。

#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;

    std::cout << "Initial size: " << numbers.size() << ", capacity: " << numbers.capacity() << std::endl;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    std::cout << "After adding elements: size: " << numbers.size() << ", capacity: " << numbers.capacity() << std::endl;

    numbers.reserve(10);
    std::cout << "After reserving space: size: " << numbers.size() << ", capacity: " << numbers.capacity() << std::endl;

    return 0;
}