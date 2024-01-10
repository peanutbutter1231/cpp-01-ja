// # チャレンジ3
// ヘッダーファイル `math_operations.h` をインクルードするC++プログラムを作成してください。
// このヘッダーファイルでは、名前空間 `MathOps` 内に基本的な算術演算 (`addition`、`subtraction`、`multiplication`、`division`) の関数を宣言します。
// これらの関数を別のファイル `math_operations.cpp` で実装し、メインのプログラムファイル `main.cpp` でこれらの関数を使用します。
// このプログラムでは、ユーザーに2つの数値と実行する演算の入力を求め、結果を表示するものとします。

#include <iostream>
#include "math_operations.h"

int main()
{
    float a{}, b{};
    char c{};

    std::cout << "Enter a calculation: ";
    std::cin >> a >> c >> b;

    //    std::cout << "Input two numbers!" << std::endl;
    //    std::cin >> a >> b;
    //    std::cout << "Input Operator! '+'or'-'or'/'or'*'" << std::endl;
    //    std::cin >> c;

    if (c == '+')
    {
        std::cout << "Result: " << MathOps::addition(a, b) << std::endl;
    }
    else if (c == '-')
    {
        std::cout << "Result: " << MathOps::subtraction(a, b) << std::endl;
    }
    else if (c == '*')
    {
        std::cout << "Result: " << MathOps::multiplication(a, b) << std::endl;
    }
    else if (c == '/')
    {
        std::cout << "Result: " << MathOps::division(a, b) << std::endl;
    }

    return 0;
}
