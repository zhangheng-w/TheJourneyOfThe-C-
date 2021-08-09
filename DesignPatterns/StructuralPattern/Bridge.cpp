/*
 * Created by weyiua on 2021/8/9.
 * 桥接模式
 * 和建造者模式有点相似
 * is-a?
 * 角色
 * Abstraction：抽象类
 * RefinedAbstraction：扩充抽象类
 * Implementor：实现类接口
 * ConcreteImplementor：具体实现类
 */
#include <iostream>
using namespace std;

//抽象的 实现
class Implementot {
public:
    virtual void operationImp() {}
};

class ConcteratImplementotA : public Implementot {
public:
    void operationImp() {
        cout << "ConcteratImplementotA :: operationImp\n";
    }
};

class ConcteratImplementotB : public Implementot {
public:
    void operationImp() {
        cout << "ConcteratImplementotB :: operationImp\n";
    }
};

class Abstraction {
public:
    Abstraction(Implementot* p) {
        imp = p;
    }

    virtual void operation() {
        cout << "Abstraction :: operation\n";
    }

protected:
    Implementot* imp;
};

class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(Implementot* p) : Abstraction(p) {

    }

    void operation() override {
        cout << "RefinedAbstraction :: operation\n";
        this->imp->operationImp();
    }

};

void BridgeTest() {
    Implementot *p = new ConcteratImplementotA();
    RefinedAbstraction r(p);
    r.operation();
}

int main(int agrc, const char *agrv[]) {
    BridgeTest();
    return 0;
}

