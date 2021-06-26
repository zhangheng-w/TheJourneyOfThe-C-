/*
by author heng  20-11-30
����дһ�������쳣��swap����

1����std::swap���������Ч�ʲ���ʱ���ṩһ��swap��Ա��������ȷ��������������쳣
2��������ṩһ��member swap����, Ҳ�ṩһ��non-member swap��������ǰ�ߡ�����class������templates��Ҳ�����⻯std::swap
3������swapʱӦ���std::swapʹ��using����ʽ��Ȼ�����swap���Ҳ����κοռ��ʸ�����
4��Ϊ���û��������͡�����templatesȫ�ػ��Ǻõģ���ǧ��Ҫ������std�ڼ���ĳЩ��std����ȫ�µĶ���
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
���ú�����swap����
ֻҪT֧��copy constructors��copy assignment������
��ָ��ָ��һ�������ں���������---pimpl�ַ�
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