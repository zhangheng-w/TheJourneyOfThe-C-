/*
by author heng  20-11-30
考虑写一个不抛异常的swap函数

1、当std::swap对你的类型效率不高时，提供一个swap成员函数，并确认这个函数不抛异常
2、如果你提供一个member swap函数, 也提供一个non-member swap用来调用前者。对于class（而非templates）也请特殊化std::swap
3、调用swap时应针对std::swap使用using声明式，然后调用swap并且不带任何空间资格修饰
4、为“用户定义类型”进行templates全特化是好的，但千万不要尝试在std内加入某些对std而言全新的东西
*/

#include <vector>
#include <iostream>
using namespace std;

class WidgetImpl {
public :
    WidgetImpl(const int& numa, const int& numb, const int& numc, const vector<double>& rhs) : a(numa), b(numb), c(numc), v(rhs) {}
private :
    int a, b, c;
    vector<double> v;

    friend ostream& operator<<(ostream& out, WidgetImpl& rhs) {
        out << "this WidgetImpl member \n"
            << "a:" << rhs.a << "\n"
            << "b:" << rhs.b << "\n"
            << "c:" << rhs.c << "\n"
            << "v:" << rhs.v.size()  << endl;
        return out;
    }
};

class Widget {
public :
    Widget(const Widget& rhs) : pImpl(rhs.pImpl) {}
    Widget(WidgetImpl* rhs) : pImpl(rhs) {}
    Widget& operator==(const Widget& rhs) {
        *pImpl = *(rhs.pImpl);
        return *this;
    }

    void swap(Widget& other) {
        using std::swap;
        swap(pImpl, other.pImpl);
    }
private :
    WidgetImpl* pImpl;

    friend ostream& operator<<(ostream& out, const Widget& rhs) {
        out << "This Widget member\n"
            << rhs.pImpl
            << endl;
        return out;
    }
};

template <typename T>
class WidgetImplTemp {
public :
    WidgetImplTemp(const T& numa, const T& numb, const T& numc, const vector<T>& num) : a(numa), b(numb), c(numc), v(num) {}

private :
    T a, b, c;
    vector<T> v;
};

template <typename T>
class WidgetTemp {
public :
    void swap(WidgetTemp<T>& rhs) {
        using std::swap;
        swap(p, rhs.p);
    }

private :
    WidgetImplTemp<T> *p;
};

/*
内置函数库swap函数
只要T支持copy constructors和copy assignment操作符
以指针指向一个对象，内含真正数据---pimpl手法
*/
namespace std_nthis {
    template <typename T>
    void swap(T& a, T& b) {
        T temp(a);
        a = b;
        b = temp;
    }

    //err
    /* template<>
    void swap<Widget>(Widget& a, Widget& b) {
        swap(a.pImpl, b.pImpl);                   //err pImpl is private 
    }*/

    template<>
    void swap<Widget>(Widget& a, Widget& b) {
        using std::swap;
        a.swap(b);              
    } 


    template<typename T>
    void swap(WidgetTemp<T>& a, WidgetTemp<T>& b) {
        a.swap(b);
    }
} 

void swapTest() {
    WidgetImpl widgeio(1,2,3, vector<double>());
    cout << widgeio;
    Widget widgeo(&widgeio);
    cout << widgeo;
    WidgetImpl widgeit(4,5,6, vector<double>());
    cout << widgeit;
    Widget widget(&widgeit);
    cout << widget;
    swap(widgeo, widget);
    widgeo.swap(widget);
    cout << widgeo << widget;
}


int main(int agrc, char const *agrv[]) {
    swapTest();
    return 0;
}