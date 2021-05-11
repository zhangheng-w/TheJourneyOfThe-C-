/*
by author heng  20-11-30
若所有的参数皆需类型转换，请为此采用non-member函数

1、如果你需要为某个函数的所有参数（包括被this指针所指的那个隐喻参数）进行类型转换，那么这个函数必须是个non-member函数
*/

#include <iostream>
using namespace std;


class Rational {
public :
    Rational(int numerator = 0, int denominator = 1)  : _numerator(numerator), _denominator(denominator) { cout << "Rational defautl-value destructor\n"; }
    int numerator() const { return _numerator; }
    int denominator() const { return _denominator; }

    /* const Rational operator*(const Rational& rhs) const {
        return Rational(_numerator * rhs.numerator(), _denominator * rhs.denominator() );
    } */
private :
    int _numerator;
    int _denominator;

    friend ostream& operator<<(ostream& out, const Rational& rhs) {
        out << rhs._numerator << " "
            << rhs._denominator << endl;
        return out;
    }
};

const Rational operator*(const Rational& lhs, const Rational& rhs) {
        return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator() );
    }

void rationalTest() {
    Rational oneEnglish(1, 8);
    Rational oneHalf(1, 2);
    Rational result = oneHalf * oneEnglish;
    cout << result;
    //result = 2 * oneHalf;                           //err   member function
    result = 2 * oneHalf;  
    cout << result;                                   //non-member function
}


int main(int agrc, char const *agrv[]) {
    rationalTest();
    return 0;
}
