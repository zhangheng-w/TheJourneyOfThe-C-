/*
 * Created by weyiua on 2021/6/21.
 * 42. �˽�typename��˫������
 *
 *  * iterator_traits<IterT>::value_type IterT������ָ�����ͬ����
 *
 *  * ����template����ʱ���ؼ���class��typename���Ի���
 *  * ��ʹ�ùؼ���typename��ʶǶ�״����������ƣ���������base class lists(������)
 *    ��member initialization list(��Ա��˺��)��������Ϊbase class���η�
 */


#include <iostream>
using namespace std;


//������ͬ��������ȫ��ͬ
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
    //IterT������ָ�����ͬ���ͣ� ����temp��ʼ��Ϊiter��ָ��
    typename iterator_traits<IterT>::value_type temp(*iter);
    typedef typename iterator_traits<IterT>::value_type value_type;
    value_type tempv(*iter);
}

int main(int agrc, const char *agrv[]) {
    return 0;
}
