#include "mystr.hpp"

// #include <iostream>
// using namespace std;

int main() {
    // 構造体の初期化
    // mystr s = {"abc"};
    // 構造体のコンストラクタ
    // mystr s = "abc";
    // mystr s("abc");

    char buf[] = "abc";
    
    mystr s = buf;
    // mystr s(buf); // 同じ？

    buf[0] = 'A';

    (s += "def") += "ghi";

    s.printn();

    mystr s1 = "123";
    s1.printn();

    printf("last of main()\n");
}