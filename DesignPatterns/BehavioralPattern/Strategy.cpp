/*
 * Created by weyiua on 2021/8/9.
 * ����ģʽ
 * ��ͬ�Ĳ��Բ�ͬ��Ч��
 * �����Դ���� Ҳ�������۾��ǲ�ͬ�Ĳ��� ͬһ�����鲻ͬ��ѡ��
 *
 * ��ɫ
 * Context: ������
 * Strategy: ���������
 * ConcreteStrategy: ���������
 */
#include <iostream>
using namespace std;

class Strategy {
public:
    virtual void algorithm() {

    }
};

class ConcreteStrategyA : public Strategy {
public:
    void algorithm() {
        cout << "ConcreteStrategyA :: algorithm\n";
    }
};

class ConcreteStrategyB : public Strategy {
public:
    void algorithm() {
        cout << "ConcreteStrategyB :: algorithm\n";
    }
};

class Context {
public:
    //ͬһ���㷨��ͬ�Ĳ��� ��ͬ�Ľ��
    void algorithm() {
        _strategy->algorithm();
    }

    void setStrategy(Strategy* s) {
        _strategy = s;
    }

private:
    Strategy* _strategy;
};

void test() {
    Context* context = new Context;
    context->setStrategy(new ConcreteStrategyA);
    context->algorithm();
    cout << endl;
    context->setStrategy(new ConcreteStrategyB);
    context->algorithm();
    delete context;
}

int main(int agrc, const char *agrv[]) {
    test();
    return 0;
}

