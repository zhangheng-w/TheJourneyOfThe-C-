/*
 * Created by weyiua on 2021/6/21.
 * 42. 了解typename的双重意义
 *
 *  * iterator_traits<IterT>::value_type IterT对象所指物的相同类型
 *
 *  * 声明template参数时，关键字class和typename可以互换
 *  * 请使用关键字typename标识嵌套从属类型名称；但不得在base class lists(基类列)
 *    或member initialization list(成员出撕裂)内以它作为base class修饰符
 */


#include <iostream>
using namespace std;


//两个相同，意义完全相同
template<typename T> class WightTypename;
template<class T> class WightClass;

template<typename T>
void print2nd(const T& t) {
    if(t.size() > 2) {
        //T::const_iterator iter(t.begin());   //err
        //T::const_iterator* x;                //err
        typename T::const_iterator iter(t.begin());
        ++iter;
        int value = *iter;
        cout << value << "\t";
    }
}

template<typename T>
void f(const T& t, typename T::iterator iter) {

}

template<typename T>
class Base {};
template<typename T>
class Nested : public Base<T> {
    Nested(int x) {}
};
template<typename T>
class Derived : public Base<T>::Nested {
public:
    typename Base<T>::Nested temp;
    explicit Derived(int x) :
        Base<T>::Nested(x) {
        typename Base<T>::Nested temp;
    }
};

template<typename IterT>
void workWithIterator(IterT iter) {
    //IterT对象所指物的相同类型， 并将temp初始化为iter所指物
    typename iterator_traits<IterT>::value_type temp(*iter);
    typedef typename iterator_traits<IterT>::value_type value_type;
    value_type tempv(*iter);
}

int main(int agrc, const char *agrv[]) {
    return 0;
}
