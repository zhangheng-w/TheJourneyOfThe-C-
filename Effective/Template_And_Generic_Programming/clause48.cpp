/*
 * Created by weyiua on 2021/6/24.
 *48. ��ʶtemplateԪ���
 *
 * * Template metaphorgramming(TMP, ģ��Ԫ���)�ɽ����������������������ڣ��������ʵ�����ڴ������͸��ߵ�ִ��Ч��
 * * TMP�ɱ���������"��������ѡ�����"�Ŀͻ��˶�����룬Ҳ���ñ������ɶ�ĳЩ�������Ͳ������ʵĴ���
 *
 */

#include <iostream>
#include <iterator>
using namespace std;


template<typename IterT, typename DistT> //������
void doAdvance(IterT& iter, DistT d) {
    if(typeid(typename std::iterator_traits<IterT>::iterator_category)
        == typeid(random_access_iterator_tag)) {
        iter += d;
    }
    else {
        if(d >= 0) { while (d--) ++iter; }
        else { while (d++) --iter; }
    }
}

//�ݹ�ģ����ֻ�
//unsigned  ?
template<unsigned  n>
struct Factorial {
    enum { value = n * Factorial<n-1>::value };
};

template<>
struct Factorial<0> {
    enum {value = 1};
};

int main(int agrc, const char *agrv[]) {
    cout << Factorial<5>::value << endl;
    cout << Factorial<10>::value << endl;
    return 0;
}