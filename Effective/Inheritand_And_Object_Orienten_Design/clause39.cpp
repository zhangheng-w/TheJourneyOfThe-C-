/*
 * Created by weyiua on 2021/6/20.
 * 39. 明智而审慎地使用private继承
 *
 * 感谢私有继承--EBO的广泛实践，这样的继承很少增加derived class的大小
 * is-a public继承
 *
 * * private继承意味着is-implemented-in-terms of(根据某物实现出)。它通常比复合的级别低，
 *   但derived class需要访问protected base class的成员，或需要重新定义继承而来的virtual函数时，这么设计是合理的
 * * 和复合不同，private继承可以造成empty base最优化。这对致力于"对象尺寸最小化"的程序库开发者而言，可能很重要
 */

#include <iostream>
using namespace std;

//private继承 base的所有都是derived class的private属性
class Person {};
class Student : private Person {};

void eat(const Person& p) {
    cout << "person eat\n";
}

void study(const Student& s) {
    cout << "student study\n";
}

void testPersonToPrivateClass() {
    Person p;
    Student s;
    eat(p);
    //eat(s); // ？err
};


class Timer {
public:
    explicit Timer(int tickFrequency) {}

    Timer() {}

    virtual void onTick() const { cout << "Timer::onTick()\n"; }
};
// err 并非好设计
class WidgetNoI : private Timer {
private:
    virtual void onTick() const { cout << "WidgetNoI::onTick()\n"; }
};


class WidgetTimer;
//一种好点的设计
class WidgetY {
public:

    WidgetY() {}
private:
    class WidgetTimer : public Timer {
    public:
        virtual void onTick() const { cout << "WidgetTimer::onTick()\n"; }
    };
    WidgetTimer _timer;
};

void testHas_aPrivatrI() {
    int num = 100;
    Timer timer(num);
    WidgetNoI widgetNoI;
    WidgetY widgetY;

    timer.onTick();
    //widgetNoI.onTick();
    //widgetY.timer.onTick(); private
}


class Empty{};
class HoldsAnInt {
private:
    int x;
    Empty e;
};

//私有继承 内存大小相同 EBO空白基类最优化
class HodlsAnIntPrivate : private Empty {
private:
    int x;
};

void testEmptySizeof() {
    cout << sizeof(HoldsAnInt)  << "\t" << sizeof(int) << endl;
    cout << sizeof(HodlsAnIntPrivate)  << "\t" << sizeof(int) << endl;
}



int main(int agrc, const char *agrv[]) {
    testPersonToPrivateClass();
    testHas_aPrivatrI();
    testEmptySizeof();
    return 0;
}

