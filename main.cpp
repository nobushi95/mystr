#include "mystr.hpp"

// #include <iostream>
// using namespace std;

// mystrがconst -> メンバなどを変更しない -> const関数しか呼べない
// const参照で渡せば、コピーが発生しない
void testConst(const mystr &s) {
    s.printn();
}

void testConstructorArg(const mystr &s) {
    s.printn();
}

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

    mystr ss = "123";
    ss.printn();

    mystr s1 = ss;
    printf("s1 [%lu]:%s\n", s1.len, s1.str);

    // コンストラクタが const char * から mystr に自動的に変換
    testConstructorArg("test constructor arg");

    printf("last of main()\n");
}