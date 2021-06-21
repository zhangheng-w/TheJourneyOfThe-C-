/*
 * Created by weyiua on 2021/6/20.
 * 39. ���Ƕ�������ʹ��private�̳�
 *
 * ��л˽�м̳�--EBO�Ĺ㷺ʵ���������ļ̳к�������derived class�Ĵ�С
 * is-a public�̳�
 *
 * * private�̳���ζ��is-implemented-in-terms of(����ĳ��ʵ�ֳ�)����ͨ���ȸ��ϵļ���ͣ�
 *   ��derived class��Ҫ����protected base class�ĳ�Ա������Ҫ���¶���̳ж�����virtual����ʱ����ô����Ǻ����
 * * �͸��ϲ�ͬ��private�̳п������empty base���Ż������������"����ߴ���С��"�ĳ���⿪���߶��ԣ����ܺ���Ҫ
 */

#include <iostream>
using namespace std;

//private�̳� base�����ж���derived class��private����
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
    //eat(s); // ��err
};


class Timer {
public:
    explicit Timer(int tickFrequency) {}

    Timer() {}

    virtual void onTick() const { cout << "Timer::onTick()\n"; }
};
// err ���Ǻ����
class WidgetNoI : private Timer {
private:
    virtual void onTick() const { cout << "WidgetNoI::onTick()\n"; }
};


class WidgetTimer;
//һ�ֺõ�����
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

//˽�м̳� �ڴ��С��ͬ EBO�հ׻������Ż�
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

