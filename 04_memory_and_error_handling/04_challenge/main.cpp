//# チャレンジ4
//`std::vector<int>` と整数型のインデックスを引数にとる関数 `element_at` を作成してください。
//この関数では、指定したインデックスにあるvectorの要素を返し、インデックスが範囲外の場合は適切なエラーメッセージとともに `std::out_of_range` 例外をスローするようにします。
//main関数で有効なインデックスと無効なインデックスの両方を指定して `element_at` を呼び出し、例外を適切に処理してください。

#include <iostream>
#include <stdexcept>
#include <vector>

int element_at(const std::vector<int> &v, int index) {
    if (index < 0 || index >= v.size()) {
        throw std::out_of_range("Index out of range");
    }
    return v[index];
}

int main() {
    std::vector<int> numbers = {1, 3, 5, 7, 9};
    try {
        std::cout << "Valid index: " << element_at(numbers, 2) << std::endl;
        std::cout << "Invalid index: " << element_at(numbers, 10) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}