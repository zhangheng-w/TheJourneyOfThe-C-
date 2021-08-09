/*
 * Created by weyiua on 2021/8/9.
 * 策略模式
 * 不同的策略不同的效果
 * 即可以打九折 也可以五折就是不同的策略 同一件事情不同的选择
 *
 * 角色
 * Context: 环境类
 * Strategy: 抽象策略类
 * ConcreteStrategy: 具体策略类
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
    //同一个算法不同的策略 不同的结果
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

