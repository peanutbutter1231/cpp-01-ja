//# チャレンジ1
//整数型の変数 `x` があります。この変数のメモリアドレスを出力するコードスニペットを書いてください。
//次に、`x` のアドレスを指す整数型のポインタ `p` を作成し、`p` が指すアドレスに格納されている値を出力します。

#include <iostream>

int main() {
    int x = 42;
    int* p = &x;

    std::cout << &x << std::endl;
    std::cout << *p << std::endl;

    return 0;
}

