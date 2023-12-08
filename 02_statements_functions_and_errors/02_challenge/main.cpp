//再帰関数factorialの宣言と定義を完成させてください。この関数は整数型の引数 `n` をとり、`n` の階乗を返します。
#include<iostream>

int factorial(int n);

int main() {
  std::cout << "Factorial of 4 is " << factorial(4) << std::endl;
  return 0;
}

int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}