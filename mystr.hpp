#include <cstdio>
#include <cstring>
// #include <cstdlib>
// #include <iostream>

// #define MY_DEBUG

struct mystr {
    char *str;
    size_t len;

    // コンストラクタ
    // mystr(const char *s) {
    //     // str = (char *)malloc(strlen(s) + 1);
    //     str = new char[strlen(s) + 1];
    //     strcpy(str, s);
    // }

    // コンストラクタ改
    mystr(const char *s) : str(NULL) {
        // str = NULL;
        // &operator=(const char *s)を利用
        // NULLのdeleteは無視されるため、NULLチェック必要なし
        *this = s;
    }

    mystr() : str(NULL) {
        // str = NULL;
        // &operator=(const char *s)を利用
        // NULLのdeleteは無視されるため、NULLチェック必要なし
        *this = "";
    }

    // コピーコンストラクタ
    // mystr(const mystr &s) {
    //     str = new char[strlen(s.str) + 1];
    //     strcpy(str, s.str);
    // }

    // コピーコンストラクタ改
    // コピーコンストラクタはconst参照のみ？
    mystr(const mystr &s) : str(NULL) {
        // str = NULL;
        // &operator=(const char *s)を利用
        // NULLのdeleteは無視されるため、NULLチェック必要なし
        *this = s.str;
    }

    // デストラクタ
    ~mystr() {
        #ifdef MY_DEBUG
        printf("~mystr: %s\n", str);
        #endif
        // free(str);
        delete[] str;
    }

    // 参照で返さないと一時オブジェクトにコピーされて返される
    // 参照で返すことによって、左辺値として代入することができる
    mystr &operator+=(const char *s) {
        char *old = str;
        len += strlen(s);
        str = new char[len + 1];
        strcpy(str, old);
        strcat(str, s);
        delete[] old;
        return *this;
    }

    mystr &operator+=(const mystr &s) {
        char *old = str;
        len += s.len;
        str = new char[len + 1];
        strcpy(str, old);
        strcat(str, s.str);
        delete[] old;
        return *this;
    }

    mystr &operator=(const char *s) {
        delete[] str;
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
        return *this;
    }

    // 左辺に来ないので&はつけない？
    mystr operator+(const mystr &s) const {
        mystr ret = *this;
        ret += s;
        return ret;
    }

    // const関数はメンバ変数の値を変更しないことを意味する
    // 戻り値がconstではない
    void printn() const {
        printf("%s\n", str);
    }

    void set(const char *s, size_t newlen) {
        char *old = str;
        len = newlen;
        str = new char[len + 1];
        strcpy(str, s);
        delete[] old;
    }
};

mystr operator+(const mystr &s1, const mystr &s2) {
    mystr ret = s1;
    ret += s2;
    return ret;
}