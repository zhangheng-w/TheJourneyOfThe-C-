/*
by author heng  20-11-30
�����еĲ�����������ת������Ϊ�˲���non-member����

1���������ҪΪĳ�����������в�����������thisָ����ָ���Ǹ�������������������ת������ô������������Ǹ�non-member����
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
