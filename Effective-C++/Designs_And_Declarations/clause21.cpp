/*
by author heng  20-11-29
必须返回对象时，别妄想返回其reference

friend函数 ---> ???

1、绝不返回pointer和reference 指向一个local stack 对象，或返回reference 指向heap-allocated 对象，
   或返回pointer或reference 指向一个local static 对象而有可能需要多个这样的对象。
*/

#include <iostream>
using namespace std;

class Rational {
public :
    Rational(int numerator = 0, int denominator = 1) : _n(numerator), _d(denominator) {}

    
private :
    int _n;
    int _d;
    friend ostream& operator<<(ostream& out, const Rational& rhs) {
        out<< "_n:" << rhs._n << ", " 
           << "_d:" << rhs._d << endl;
        return out;
    }

    friend const Rational operator*(const Rational& lhs, const Rational& rhs) {
        return Rational(lhs._d * rhs._d, lhs._n * rhs._n);
    }
    /* 
    在stack创建
    friend const Rational& operator*(const Rational& lhs, const Rational& rhs) { 
        Rational result(lhs._d * rhs._d, lhs._n * rhs._n);
        return result;
    }
    在heap    
    friend const Rational& operator*(const Rational& lhs, const Rational& rhs) { 
        Rational* result = new Rational(lhs._d * rhs._d, lhs._n * rhs._n);
        return *result;
    }

    const Rational& operator*(const Rational& lhs, const Rational& rhs) { 
        static Rational result;                                        //static多线程安全性问题
        result = r(lhs._d * rhs._d, lhs._n * rhs._n);
        return result;
    }
    */

   friend bool operator==(const Rational& lhs, const Rational& rhs) {
       return lhs._n==rhs._n && lhs._d==rhs._d;
   }

};

void rationalTest() {
    Rational a(1, 2);
    Rational b(3, 5);
    Rational c = (a * b);
    cout << a;
    cout << c;
    cout << (a == b);
}

int main(int agrc, char const *agrv[]) {
    rationalTest();
    return 0;
}