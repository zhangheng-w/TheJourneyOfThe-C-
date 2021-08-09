/*
 * Created by weyiua on 2021/8/2.
 * ���󹤳�ģʽ
 * �Ѳ�Ʒ������� -> ������Ʒ��
 * ��ͬ�Ĺ���������ͬ�Ĳ�Ʒ
 * ���� �������� -> ���������յ� ��������
 * ���� ���Ĺ��� -> �������Ŀյ� ���ķ���
 *
 * ��ɫ
 * AbstractFactory�����󹤳�
 * ConcreteFactory�����幤��
 * AbstractProduct�������Ʒ
 * Product�������Ʒ
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
    //����ָ��
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