/*
 * Created by weyiua on 2021/8/9.
 * 状态模式
 * 对象不同的状态有不同的行为
 *
 * 角色
 * Context: 环境类
 * State: 抽象状态类
 * ConcreteState: 具体状态类
 */

#include <iostream>
using namespace std;

class State {
public:
    virtual void handle() {

    }
};

class ConcreteStateA : public State {
public:
    void handle() {
        cout << "ConcreteStateA :: handle\n";
    }
};

class ConcreteStateB : public State {
public:
    void handle() {
        cout << "ConcreteStateB :: handle\n";
    }
};

class Context {
public:
    //改变状态 使之有不同的行为
    void changeState(State* s) {
        _state = s;
    }

    void request() {
        cout << "Context :: request\n";
        _state->handle();
    }
private:
    State* _state;
};

void test() {
    Context* context = new Context;
    State* s1 = new ConcreteStateA;
    State* s2 = new ConcreteStateB;
    context->changeState(s1);
    context->request();
    cout << endl;
    context->changeState(s2);
    context->request();
}

int main(int agrc, const char *agrv[]) {
    test();
    return 0;
}





