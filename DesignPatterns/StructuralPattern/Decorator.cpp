/*
 * Created by weyiua on 2021/8/9.
 * 装饰模式
 *
 * 继承机制
 * 关联机制
 *
 * 角色
 * Component: 抽象构件
 * ConcreteComponent: 具体构件
 * Decorator: 抽象装饰类
 *  ConcreteDecorator: 具体装饰类
 */

#include <iostream>
using namespace std;

class Component {
public:
    virtual void operation() {}
};

class ComcreteComponent : public Component {
public:
    void operation() {
        cout << "ComcreteComponent :: operation\n";
    }
};

class Decortor : public Component {
public:
    Decortor(Component* c) : _component(c) {}
    virtual void operation() {
        _component->operation();
    }
private:
    Component* _component;
};

class ConcreteDeconatorA : public Decortor {
public:
    ConcreteDeconatorA(Component* c) : Decortor(c) {

    }

    void addBehavior() {
        cout << "ConcreteDeconatorA :: addBehavior\n";
    }

    void operation() {
        cout << "ConcreteDeconatorA :: operation\n";
        Decortor::operation();
        addBehavior();
    }
};

class ConcreteDeconatorB : public Decortor {
public:
    ConcreteDeconatorB(Component* c) : Decortor(c) {

    }
    void addBehavior() {
        cout << "ConcreteDeconatorB :: addBehavior\n";
    }

    void operation() {
        cout << "ConcreteDeconatorB :: operation\n";
        Decortor::operation();
        addBehavior();
    }
};

void DecortorTest() {
    Component *component = new ComcreteComponent;
    ConcreteDeconatorA concreteDeconatorA(component);
    concreteDeconatorA.operation();
}

int main(int agrc, const char *agrv[]) {
    DecortorTest();
    return 0;
}

