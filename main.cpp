#include "mystr.hpp"
#include <ctime>
#include <string>
// #include <iostream>

using namespace std;

// mystrがconst -> メンバなどを変更しない -> const関数しか呼べない
// const参照で渡せば、コピーが発生しない -> const参照のみでコンストラクタが走る？
void testConst(const mystr &s) {
    s.printn();
}

// ただのクラス参照ではコンストラクタは走らない？
void testRef(mystr &s) {
    s.printn();
}

template <class T>
void benchmark() {
    double t1 = static_cast<double>(clock());
    T s;
    for (int i = 0; i < 500000; i++) {
        s += "a";
    }
    double t2 = static_cast<double>(clock());
    printf("%.2f sec\n", (t2 - t1) / CLOCKS_PER_SEC);
}

int main() {
    // 構造体の初期化
    // mystr s = {"abc"};
    // 構造体のコンストラクタ
    // mystr s = "abc";
    // mystr s("abc");

    // char buf[] = "abc";
    
    // mystr s = buf;
    // // mystr s(buf); // 同じ

    // buf[0] = 'A';

    // (s += "def") += "ghi";

    // s.printn();

    // mystr ss = "123";
    // ss.printn();

    // mystr s1 = ss;
    // printf("s1 [%lu]:%s\n", s1.len, s1.str);

    // コンストラクタが const char * から mystr に自動的に変換 -> const参照だから？
    testConst("test constructor arg");

    // ただの参照なので、これはできない -> コンストラクタが走らない？
    // testRef("test reference constrructor arg");

    // インスタンスを渡すのはOKっぽい
    mystr tr = "test reference constructor arg";
    testRef(tr);

    // 非メンバ関数で+演算子をオーバーロード
    // 第1引数に融通が効くように
    mystr a = "abc";
    mystr b = "123" + a;
    b.printn();

    benchmark<string>();
    benchmark<mystr>();

    printf("last of main()\n");
}