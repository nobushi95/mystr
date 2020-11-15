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
void benchmark1() {
    double t1 = static_cast<double>(clock());
    T s;
    for (int i = 0; i < 500000; i++) {
        s += "a";
    }
    double t2 = static_cast<double>(clock());
    printf("benchmark1 : %.2f sec\n", (t2 - t1) / CLOCKS_PER_SEC);
}

template <class T>
void benchmakr2() {
    T s1, s2;
    for (int i = 0; i < 500000; i++) {
        s1 += "a";
    }
    double t1 = static_cast<double>(clock());
    for (int i = 0; i < 500000; i++) {
        s2 = s1;
    }
    double t2 = static_cast<double>(clock());
    printf("benchmark2 : %.2f sec\n", (t2 - t1) / CLOCKS_PER_SEC);;
}

template <class T>
void buffShareTest() {
    T s1 = "abc";
    T s2 = s1;
    s1 += "def";
    printf("s1 : %d, %s\n", s1.length(), s1.c_str());
    printf("s2 : %d, %s\n", s2.length(), s2.c_str());
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

    // benchmark1<string>();
    // benchmark1<mystr>();

    // benchmakr2<string>();
    // benchmakr2<mystr>();

    buffShareTest<string>();
    buffShareTest<mystr>();

    printf("last of main()\n");
}