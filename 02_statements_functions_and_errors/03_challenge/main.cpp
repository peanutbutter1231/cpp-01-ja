// C++の関数 `power` は、`base` と `exponent` という2つの引数をとります。
//`exponent` のデフォルト値は2で、`power` は `base` を `exponent` 回累乗した結果を返します。
// baseを3、exponentを4としてこの関数を呼び出してください。

#include <iostream>
#include <string>

int power(int base, int exponent=2);

int main()
{
    std::cout << power(3,4) << std::endl;
    return 0;
}

int power(int base, int exponent)
{
    int result = 0;
    result = base * base;
    exponent = exponent - 2;

    for (int i = exponent; i > 0; i--)
    {
        result = result * base;
    }
    
    return result;
}