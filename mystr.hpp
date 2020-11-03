#include <cstdio>
#include <cstring>
// #include <cstdlib>
// #include <iostream>

struct mystr {
    char *str;

    // コンストラクタ
    // mystr(const char *s) {
    //     // str = (char *)malloc(strlen(s) + 1);
    //     str = new char[strlen(s) + 1];
    //     strcpy(str, s);
    // }

    // コンストラクタ改
    mystr(const char *s) {
        str = NULL;
        // &operator=(const char *s)を利用
        *this = s;
    }

    mystr() {
        str = NULL;
        // &operator=(const char *s)を利用
        *this = "";
    }

    // コピーコンストラクタ
    // mystr(const mystr &s) {
    //     str = new char[strlen(s.str) + 1];
    //     strcpy(str, s.str);
    // }

    // コピーコンストラクタ改
    mystr(const mystr &s) {
        str = NULL;
        // &operator=(const char *s)を利用
        *this = s.str;
    }

    // デストラクタ
    ~mystr() {
        printf("~mystr: %s\n", str);
        // free(str);
        delete[] str;
    }

    // 参照で返さないと一時オブジェクトにコピーされて返される
    // 参照で返すことによって、左辺値として代入することができる
    mystr &operator+=(const char *s) {
        char *old = str;
        int len = strlen(str) + strlen(s);
        str = new char[len + 1];
        strcpy(str, old);
        strcat(str, s);
        delete[] old;
        return *this;
    }

    mystr &operator=(const char *s) {
        delete[] str;
        str = new char[strlen(s) + 1];
        strcpy(str, s);
        return *this;
    }

    // const関数はメンバ変数の値を変更しないことを意味する
    // 戻り値がconstではない
    void printn() const {
        printf("%s\n", str);
    }
};

void testConst(const mystr &s) {
    // mystrがconst -> メンバなどを変更しない -> const関数しか呼べない
    s.printn();
}