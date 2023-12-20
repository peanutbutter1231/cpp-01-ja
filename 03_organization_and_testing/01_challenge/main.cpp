//# チャレンジ1
//次のコードがあります。
//このプログラムをコンパイルして実行し、エラーの原因となっているコードを修正してください。その際、コードを削除するのではなく、コードを追加して修正してください。

#include <iostream>
#include "temp_sensor.h"

float readTemperature();

int main() {
    std::cout << "Temperature reading: " << readTemperature() << std::endl;
    return 0;
}