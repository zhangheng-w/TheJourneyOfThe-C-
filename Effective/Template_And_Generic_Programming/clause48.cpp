/*
 * Created by weyiua on 2021/6/24.
 *48. 认识template元编程
 *
 * * Template metaphorgramming(TMP, 模版元编程)可将工作由运行期移往编译期，因而得以实现早期错误侦测和更高的执行效率
 * * TMP可被用来生成"基于政策选择组合"的客户端定义代码，也可用避免生成对某些特殊类型并不合适的代码
 *
 */

#include <iostream>
#include <iterator>
using namespace std;


template<typename IterT, typename DistT> //迭代器
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

//递归模版具现化
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