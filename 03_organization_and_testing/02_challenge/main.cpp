//# チャレンジ2
//C++11以降では4番目のタイプの記憶域期間が追加されています。何という記憶域期間ですか。⇒スレッド記憶域期間：スレッドが開始してから終了するまで
//この記憶域期間を持つ `int` 型の変数 `thread_data` を宣言し、値10で初期化するには、どのようにしますか。

#include <pthread.h>
#include <iostream>

__thread int thread_data = 10;

int main(){
    std::cout << thread_data << std::endl;
}