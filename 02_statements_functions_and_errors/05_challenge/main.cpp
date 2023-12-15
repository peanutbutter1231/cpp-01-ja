//ユーザーが入力した3つの数値の平均を計算するプログラムがあります。さまざまな値を入力してこのプログラムをテストしてください。プログラムは適切に動作しますか。適切に動作しない場合は、想定どおりの出力になるようにプログラムを修正してください。

#include <iostream>
int main() {
    float num1;
    float num2;
    float num3;
    float average;

    std::cout << "Enter three numbers: ";
    std::cin >> num1 >> num2 >> num3;

    //average = (num1 + num2 + num3) / 3;
    average = static_cast<float>(num1 + num2 + num3) / 3;

    std::cout << "Average is: " << average << std::endl;

    return 0;
}
