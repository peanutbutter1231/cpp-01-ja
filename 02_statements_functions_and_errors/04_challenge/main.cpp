// ユーザーが入力した2つの数値のうち大きいほうの値を求めるプログラムがありますが、正しく動作しません。デバッグして修正してください。

#include <iostream>

int main()
{
    int num1;
    int num2;
    int max;

    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    if (num1 > num2)
    {
        max = num1;
    }
    else if (num1 < num2)
    {
        max = num2;
    }
    else
    {
        max = num1;
    }

    std::cout << "Maximum is: " << max << std::endl;

    return 0;
}