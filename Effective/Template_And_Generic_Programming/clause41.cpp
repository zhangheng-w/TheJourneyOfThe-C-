/*
 * Created by weyiua on 2021/6/21.
 * 41. 了解隐式接口的编译期多态
 *
 * * class 和 template都支持接口和多态
 * * 对class而言接口都是显式的，以函数签名为中心。多态则是通过virtual函数发生于运行期
 * * 对template参数而言，接口是隐式的，奠基于有效的表达式，多态则是通过template具体化和函数重载解析发生于编译器
 */

#include <iostream>
using namespace std;

//显式接口，运行期多态
class Wight {
public:
    Wight() {}
    virtual ~Wight() {}
    virtual size_t size() const { return 11; }
    virtual void normalize() { cout << "Wight::normalizer\n"; }
    void swap(Wight& w) {}

    bool operator!=(Wight& w) {
        return true;
    }
};

Wight someNastyWidget;
void doProcessing(Wight& w) {
    if(w.size() > 10 && w != someNastyWidget) {
        Wight temp(w);
        temp.normalize();
        temp.swap(w);
    }
}

//someNastyWidget 类型必须可以隐式转换T  才能比较!=
//其中w必需要有函数size normalize 和 swap
template <typename T>
void doProcessingTemp(T& w) {
    if(w.size() > 10 && w != someNastyWidget) {
        T temp(w);
        temp.normalize();
        temp.swap(w);
    }
}

void testWight() {
    Wight w;
    doProcessing(w);
    doProcessingTemp<Wight>(w);
    //doProcessingTemp<int>(w); //err类型不同
}

int main(int agrc, const char *agrv[]) {
    testWight();
    return 0;
}