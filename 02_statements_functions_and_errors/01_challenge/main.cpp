//ユーザーに数値の入力を求め、その値が正、負、ゼロのどれであるかを表示するプログラム
#include<iostream>

int main(){
    int num;
    std::cout << "Please Input Number!" << std::endl;
    std::cin >> num;

    if (num > 0){
        std::cout << "The Number is Positive" << std::endl;
    }
    else if(num < 0){
        std::cout << "The Number is Negative" << std::endl;
    }
    else{
        std::cout << "The Number is Zero" << std::endl;
    }
}