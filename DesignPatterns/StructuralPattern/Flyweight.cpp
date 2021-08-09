/*
 * Created by weyiua on 2021/8/9.
 * ��Ԫģʽ
 * ��Ԫ���� ͨ����Ԫ�� ά���������Ԫ��
 *
 *
 * ��ɫ
 * Flyweight: ������Ԫ��
 * ConcreteFlyweight: ������Ԫ��
 * UnsharedConcreteFlyweight: �ǹ��������Ԫ��
 * FlyweightFactory: ��Ԫ������
 */

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Flyweight {
public:
    virtual void operation() {

    }
};

class OneFly : public Flyweight {
public:
    int initOne() {
        cout << "OneFly :: initOne\n";
        return 1;
    }

    void operation() {
        cout << "OneFly :: operation\n";
        initOne();
    }
};

class TwoFly : public Flyweight {
public:
    int initTwo() {
        cout << "TwoFly :: initOne\n";
        return 2;
    }

    void operation() {
        cout << "TwoFly :: operation\n";
        initTwo();
    }
};

class FlyweightFactory {
public:
    void getFlyweight(string s) {
        if(_map.count(s)) {
            cout << "Operation\n";
            _map[s]->operation();
        } else {
            if(s == "One") {
                _map[s] = new OneFly;
            } else if(s == "Two") {
                _map[s] = new TwoFly;
            } else {
                _map[s] = new Flyweight;
            }
        }
    }

private:
    map<string, Flyweight*> _map;
};

void Client() {
    FlyweightFactory factory;
    factory.getFlyweight("One");
    cout << "\n";
    factory.getFlyweight("One");
    factory.getFlyweight("Two");
    cout << "\n";
    factory.getFlyweight("Two");
    factory.getFlyweight("O");
}

int main(int agrc, const char *agrv[]) {
    Client();
    return 0;
}
