/*
 * Created by weyiua on 2021/8/9.
 * 观察者模式
 *
 * 目标改变-即通知所有的观察者目标改变了
 *
 * Subject: 目标
 * ConcreteSubject: 具体目标
 * Observer: 观察者
 * ConcreteObserver: 具体观察者
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Obeserver {
public:
    virtual void updata() {

    }
};

class Subject {
public:
    //发生改变 通报
    void attach(Obeserver* p) {
        _ivec.push_back(p);
        notify();
        cout << endl;
    }

    void detach(Obeserver* p) {
        auto it = find(_ivec.begin(), _ivec.end(), p);
        if(it != _ivec.end()) {
            _ivec.erase(it);
            notify();
            cout << endl;
        }
    }

private:
    vector<Obeserver*> _ivec;

    void notify() {
        for(auto p : _ivec) {
            p->updata();
        }
    }
};

class ConctreteSubject : public Subject {
public:
    ConctreteSubject() : stata(0) {

    }
    int getStata() const { return stata; }
    void setStata(int a) { stata = a; }
private:
    int stata;
};

class ConcreteObeserver : public Obeserver {
public:
    ConcreteObeserver(int num) : obeserverStata(num) {

    }

    void updata() {
        cout << "ConcreteObeserver :: updata _" << obeserverStata << endl;
    }
private:
    int obeserverStata;
};

void test() {
    Subject *subject = new ConctreteSubject;
    subject->attach(new ConcreteObeserver(1));
    subject->attach(new ConcreteObeserver(10));
    auto p = new ConcreteObeserver(-11);
    subject->attach(new ConcreteObeserver(0));
    subject->attach(new ConcreteObeserver(100));
    subject->attach(p);
    subject->detach(p);
}

int main(int agrc, const char *agrv[]) {
    test();
    return 0;
}