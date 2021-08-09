/*
 * Created by weyiua on 2021/8/9.
 * 适配器模式
 * 分为对象适配器和类适配器
 *
 * 对象适配器 例如STL中的shack和queue都由deque适配而来的 底层都是deque
 * 将目标类和适配者解耦 增加了类的透明性个复用性
 *
 * 类适配器 c++中用多继承实现
 * 将多个适配器适配到同一目标
 *
 * 角色
 * Target：目标抽象类
 * Adapter：适配器类
 * Adaptee：适配者类
 * Client：客户类
 */

#include <iostream>
using namespace std;

class Adaptee {
public:
    void toAdapteeSpRequest() {
        cout << "Adaptee ToAdapteeSpResquest\n";
    }
};


class Target {
public:
    virtual void request() { cout << "Target :: request\n"; }
};

class Adapter : public Target {
public:
    Adapter(const Adaptee& a) : adaptee(a) {}

    void request() {
        cout << "Adapter :: request\n";
        adaptee.toAdapteeSpRequest();
    }
private:
    Adaptee adaptee;
};

void objectAdapterTest() {
    Adaptee a;
    Adapter adapter(a);
    adapter.request();
}

//类适配器 多继承

class Adapter2 : public Target, Adaptee {
public:
    void request() {
        cout << "Adapter :: request\n";
        Adaptee::toAdapteeSpRequest();
    }
};

void classAdapterTest() {
    Adapter2 adapter2;
    adapter2.request();
}


int main(int agrc, const char *agrv[]) {
    objectAdapterTest();
    classAdapterTest();
    return 0;
}
