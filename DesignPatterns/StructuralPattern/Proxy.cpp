/*
 * Created by weyiua on 2021/8/9.
 * 代理模式
 * 间接传递 就像中间有个人把消息给了目标
 *
 * 角色
 * Subject: 抽象主题角色
 * Proxy: 代理主题角色
 * RealSubject: 真实主题角色
 */

#include <iostream>
using namespace std;

class Subject {
public:
    virtual void request() {}
};

class RealSubjext : public Subject {
public:
    void request() {
        cout << "RealSubjext :: request\n";
    }
};

class Proxy : public Subject{
public:
    Proxy() {
        subject = new RealSubjext;
    }

    void request() {
        cout << "ProXy :: request\n";
        preRequest();
        this->subject->request();
        afterRequest();
    }


    void preRequest() {
        cout << "Proxy :: preRequest\n";
    }

    void afterRequest() {
        cout << "Proxy :: afterRequest\n";
    }

private:
    Subject* subject;
};

void Client() {
    Subject *subject = new Proxy;
    subject->request();
}

int main(int agrc, const char *agrv[]) {
    Client();
    return 0;
}