/*
 * Created by weyiua on 2021/6/23.
 * 47. 请使用traits class表现类型信息
 *
 * 迭代器
 * Input迭代器
 * Output迭代器
 * Forward迭代器
 * Bidirectional迭代器 可以向前 还可以向后 set map
 * Random Access迭代器   常量时间内向前或向后跳跃任意位置 vector string
 *
 * * 建立一组重载函数(身份像劳工)或函数模版(例如 doAdvance)，彼此间的差异只在于各自的traits参数，令每个函数实现码与其接受traits信息相应和
 * * 建立一个控制函数(身份像工头)或函数模版(例如 advance)， 它调用上述的"劳工函数"并传递traits class所提供的信息
 *
 * * Traits class使得"类型相关信息"在编译器可用。它们以template和"template 特化"完成实现
 * * 整合重载技术(overloading)后, traits class有可能在编译期对类型执行if...else测试
 */
#include <iterator>
using namespace std;

/*
  ///  Marking input iterators.
  struct input_iterator_tag { };

  ///  Marking output iterators.
  struct output_iterator_tag { };

  /// Forward iterators support a superset of input iterator operations.
  struct forward_iterator_tag : public input_iterator_tag { };

  /// Bidirectional iterators support a superset of forward iterator
  /// operations.
  struct bidirectional_iterator_tag : public forward_iterator_tag { };

  /// Random-access iterators support a superset of bidirectional
  /// iterator operations.
  struct random_access_iterator_tag : public bidirectional_iterator_tag { };
  //@}
 */

struct Input_Iterator_tag {};
struct Output_Iterator_tag {};
struct Forward_Iterator_tag : public Input_Iterator_tag {};
struct Bidirectional_Iterator_tag : public Forward_Iterator_tag {};
struct Random_Access_Iterator_tag : public Bidirectional_Iterator_tag {};

template<typename T>
class Deque {
public:
    class Iterator {
    public:
        typedef random_access_iterator_tag iterator_categorg;
    };
};

template<typename T>
class List {
public:
    class Iterator {
    public:
        typedef bidirectional_iterator_tag iterator_categorg;
    };
};



template<typename IterT, typename DistT> //随机跳跃迭代器
void doAdvance(IterT& iter, DistT d);
//膨胀 函数重载
template<typename IterT, typename DistT>
void advance(IterT& iter, DistT d) {
    /*if(typeid(typename std::iterator_traits<IterT>::iterator_category) == typeid(std::random_access_iterator_tag)) {

    }*/
    doAdvance(iter, d, typename iterator_traits<IterT>::iterator_category());

}
template<typename IterT, typename DistT> //随机跳跃迭代器
void doAdvance(IterT& iter, DistT d, random_access_iterator_tag) {
    iter += d;
}
template<typename IterT, typename DistT> //向前向后迭代器
void doAdvance(IterT& iter, DistT d, bidirectional_iterator_tag) {
    if(d >= 0) { while (d--) ++iter; }
    else { while (d++) --iter; }
}
template<typename IterT, typename DistT> //向前迭代器 不能向后
void doAdvance(IterT& iter, DistT d, std::input_iterator_tag) {
    if(d < 0) {
        throw out_of_range("bad Distance");
    }
    while (d--) ++iter;
}

int main(int agrc, const char *agrv[]) {

    return 0;
}