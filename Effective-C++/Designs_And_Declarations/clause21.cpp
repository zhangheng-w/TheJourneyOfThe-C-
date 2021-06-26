/*
by author heng  20-11-29
���뷵�ض���ʱ�������뷵����reference

friend���� ---> ???

1����������pointer��reference ָ��һ��local stack ���󣬻򷵻�reference ָ��heap-allocated ����
   �򷵻�pointer��reference ָ��һ��local static ������п�����Ҫ��������Ķ���
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
    ��stack����
    friend const Rational& operator*(const Rational& lhs, const Rational& rhs) { 
        Rational result(lhs._d * rhs._d, lhs._n * rhs._n);
        return result;
    }
    ��heap    
    friend const Rational& operator*(const Rational& lhs, const Rational& rhs) { 
        Rational* result = new Rational(lhs._d * rhs._d, lhs._n * rhs._n);
        return *result;
    }

    const Rational& operator*(const Rational& lhs, const Rational& rhs) { 
        static Rational result;                                        //static���̰߳�ȫ������
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