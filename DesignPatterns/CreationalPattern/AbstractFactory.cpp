/*
 * Created by weyiua on 2021/8/2.
 * 抽象工厂模式
 * 把产品抽象出来 -> 创建产品族
 * 不同的工厂创建不同的产品
 * 例如 格力工厂 -> 创建格力空调 格力风扇
 * 例如 美的工厂 -> 创建美的空调 美的风扇
 *
 * 角色
 * AbstractFactory：抽象工厂
 * ConcreteFactory：具体工厂
 * AbstractProduct：抽象产品
 * Product：具体产品
 */
#include <iostream>
using namespace std;

class AbstProductA {
public:
    virtual void use() {}
};

class AbstProductA1 : public AbstProductA {
public:
    void use() {
         cout << "Use AbstProductA1" << endl;
    }
};

class AbstProductA2 : public AbstProductA {
public:
    void use() {
        cout << "Use AbstProductA2" << endl;
    }
};

class AbstProductB {
public:
    virtual void eat() {}
};

class AbstProductB1 : public AbstProductB {
public:
    void eat() {
        cout << "Eat AbstProductB1" << endl;
    }
};

class AbstProductB2 : public AbstProductB {
public:
    void eat() {
        cout << "Eat AbstProductB2" << endl;
    }
};

class Factory {
public :
    virtual AbstProductA* creatPA() { cout << "Create : "; }
    virtual AbstProductB* creatPB() { cout << "Create : "; }
};

class Factory1 : public Factory {
public:
    AbstProductA* creatPA() {
        Factory::creatPA();
        return new AbstProductA1();
    }

    AbstProductB* creatPB() {
        Factory::creatPB();
        return new AbstProductB1();
    }
};

class Factory2 : public Factory {
public:
    AbstProductA* creatPA() {
        Factory::creatPA();
        return new AbstProductA2();
    }

    AbstProductB* creatPB() {
        Factory::creatPB();
        return new AbstProductB2();
    }
};

void AbstractFactory() {
    Factory *factory = new Factory1;
    AbstProductA *pA = factory->creatPA();
    pA->use();
    AbstProductB *pB = factory->creatPB();
    pB->eat();
    //悬空指针
    delete factory;
    delete pA;
    delete pB;
    factory = new Factory2;
    pA = factory->creatPA();
    pA->use();
    pB = factory->creatPB();
    pB->eat();
    delete factory;
    delete pA;
    delete pB;
}

int main(int agrc, const char *agrv[]) {
    AbstractFactory();
    return 0;
}