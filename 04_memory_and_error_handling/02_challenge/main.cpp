//# チャレンジ2
//2つの整数型のポインタを引数にとり、これらのポインタが指す値を入れ替える関数 `swap_int` を作成してください。
//次に、main関数からこの関数を呼び出し、値が入れ替わっていることを確認します。

#include <iostream>

void swap_int(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a = 10;
    int b = 20;

    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swap_int(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    return 0;
}
