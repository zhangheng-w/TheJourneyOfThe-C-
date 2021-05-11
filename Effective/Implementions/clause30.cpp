/*
 * Created by heng on 2020/12/23.
 * ͸���˽�inlining����������
 *
 * 1���������inlining������С�͡���Ƶ�����õĺ������ϡ����ʹ�պ���Թ��̺Ͷ��������������ף�
 * Ҳ��ʹǱ�ڵĴ�������������С�����ǳ�����ٶ������������
 * 2����Ҫֻ��Ϊfunction templates������ͷ�ļ��У��ͽ���������Ϊinline
*/

#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    int age() const { return theAge; }

private:
    int theAge;
};

template <typename T>
inline const T& max(const T& a, const T& b) {
    return a < b ? b : a;
}

inline void f() { cout << "this funation\n"; }
void (*pf)() = f;
void test() {
    f();
    pf();
}

class Base {
public:
    Base(const string &bm1, const string &bm2) : bm1(bm1), bm2(bm2) {}
    Base() {
        try {
            bm1 = string();
            bm2 = string();
        } catch (bad_alloc) {
            throw ;
        }
    }

    virtual ~Base() {

    }

private:
    string bm1, bm2;
};
class Derived : public Base {
public:
    Derived() ;

private:
    string dm1, dm2, dm3;
};
Derived::Derived() {
    Base();
    try {
        dm1 = string();
    } catch (bad_alloc) {
        Base::~Base();
        throw ;
    }
    try {
        dm2 = string();
    } catch (bad_alloc) {
        dm1.std::string::~string();
        Base::~Base();
        throw ;
    }
    try {
        dm3 = string();
    } catch (bad_alloc) {
        dm1.std::string::~string();
        dm2.std::string::~string();
        Base::~Base();
        throw ;
    }


}

int main(int agrc, char const *agrv[]) {
    test();
    return 0;
}