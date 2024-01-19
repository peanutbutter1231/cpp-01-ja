//# チャレンジ3
//`std::vector<int>` を引数にとり、各要素の値を2倍にした新しい `std::vector<int>` を返す関数 `double_elements` を作成してください。
//次に、範囲ベースのforループを使用して、元のvectorと新しいvectorの両方の要素を出力します。

#include <iostream>
#include <vector>

std::vector<int> double_elements(const std::vector<int>& v){
    std::vector<int> result;
    for(int element : v) {
        result.push_back(element * 2);
    }
    return result;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    for(int x : numbers){
        std::cout << x << " ";
    }
    std::cout << "\n";

    for(int y : double_elements(numbers)){
        std::cout << y << " "; 
    }
    std::cout << std::endl;

    return 0;
}