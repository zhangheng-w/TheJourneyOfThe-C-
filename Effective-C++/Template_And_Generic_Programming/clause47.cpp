/*
 * Created by weyiua on 2021/6/23.
 * 47. ��ʹ��traits class����������Ϣ
 *
 * ������
 * Input������
 * Output������
 * Forward������
 * Bidirectional������ ������ǰ ��������� set map
 * Random Access������   ����ʱ������ǰ�������Ծ����λ�� vector string
 *
 * * ����һ�����غ���(������͹�)����ģ��(���� doAdvance)���˴˼�Ĳ���ֻ���ڸ��Ե�traits��������ÿ������ʵ�����������traits��Ϣ��Ӧ��
 * * ����һ�����ƺ���(�����ͷ)����ģ��(���� advance)�� ������������"�͹�����"������traits class���ṩ����Ϣ
 *
 * * Traits classʹ��"���������Ϣ"�ڱ��������á�������template��"template �ػ�"���ʵ��
 * * �������ؼ���(overloading)��, traits class�п����ڱ����ڶ�����ִ��if...else����
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



template<typename IterT, typename DistT> //�����Ծ������
void doAdvance(IterT& iter, DistT d);
//���� ��������
template<typename IterT, typename DistT>
void advance(IterT& iter, DistT d) {
    /*if(typeid(typename std::iterator_traits<IterT>::iterator_category) == typeid(std::random_access_iterator_tag)) {

    }*/
    doAdvance(iter, d, typename iterator_traits<IterT>::iterator_category());

}
template<typename IterT, typename DistT> //�����Ծ������
void doAdvance(IterT& iter, DistT d, random_access_iterator_tag) {
    iter += d;
}
template<typename IterT, typename DistT> //��ǰ��������
void doAdvance(IterT& iter, DistT d, bidirectional_iterator_tag) {
    if(d >= 0) { while (d--) ++iter; }
    else { while (d++) --iter; }
}
template<typename IterT, typename DistT> //��ǰ������ �������
void doAdvance(IterT& iter, DistT d, std::input_iterator_tag) {
    if(d < 0) {
        throw out_of_range("bad Distance");
    }
    while (d--) ++iter;
}

int main(int agrc, const char *agrv[]) {

    return 0;
}