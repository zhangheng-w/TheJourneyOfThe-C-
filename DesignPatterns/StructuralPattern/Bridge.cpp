/*
 * Created by weyiua on 2021/8/9.
 * �Ž�ģʽ
 * �ͽ�����ģʽ�е�����
 * is-a?
 * ��ɫ
 * Abstraction��������
 * RefinedAbstraction�����������
 * Implementor��ʵ����ӿ�
 * ConcreteImplementor������ʵ����
 */
#include <iostream>
using namespace std;

//����� ʵ��
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

