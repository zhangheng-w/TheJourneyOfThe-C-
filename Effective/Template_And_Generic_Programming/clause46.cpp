/*
 * Created by weyiua on 2021/6/23.
 * 46. 需要类型转换时请为模版定义非成员函数
 *
 * * 当我编写一个class template，而它所提供之"于此template相关的"函数支持"所以参数之隐式类型转换"时，请将那些函数定义为"class template内部的friend函数"
 */

template<typename T>
class Rational {
public:
    Rational(const T& num = 0,
             const T& den = 1)  : n(num), d(den) {}
    const T numerator() const { return n;}
    const T denominator() const { return d;}
private:
    T n;
    T d;
};

template<typename T>
const Rational<T> operator* (const Rational<T>& lhs, const Rational<T>& rhs) {
    return lhs;
}

int testR() {
    Rational<int> one(1, 2);
    //Rational<int> two  = one * 1;   //err
}

template<typename T>
class Rational_friend {
public:
    Rational_friend(const T& num = 0,
             const T& den = 1)  : n(num), d(den) {}
    const T numerator() const { return n;}
    const T denominator() const { return d;}

    friend const Rational_friend  operator*(const Rational_friend& lhs, const Rational_friend& rhs);
private:
    T n;
    T d;
};

template<typename T>
const Rational_friend<T> operator* (const Rational_friend<T>& lhs, const Rational_friend<T>& rhs) {
    return lhs;
}

int testRF() {
    Rational_friend<int> one(1, 2);
    Rational_friend<int> two  = one * 1;
}

template<typename T>
class Rational_friend_toClass {
public:
    Rational_friend_toClass(const T& num = 0,
                    const T& den = 1)  : n(num), d(den) {}
    const T numerator() const { return n;}
    const T denominator() const { return d;}

    static const Rational_friend_toClass<T> doMuliply(const Rational_friend_toClass<T>& lhs, const Rational_friend_toClass<T>& rhs) {
        return Rational_friend_toClass<T>(lhs.numerator() * rhs.numerator(),
                                          lhs.denominator() * rhs.denominator());
    }

    friend const Rational_friend_toClass  operator*(const Rational_friend_toClass& lhs, const Rational_friend_toClass& rhs) {
        return doMuliply(lhs, rhs);
    }
private:
    T n;
    T d;
};

int main(int agrc, const char *agrv[]) {
    return 0;
}