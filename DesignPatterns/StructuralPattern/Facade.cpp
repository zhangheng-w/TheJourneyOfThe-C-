/*
 * Created by weyiua on 2021/8/9.
 * 外观模式
 * 将所有的外观通过一个系统完成
 * 就像你一眼看到的外观 是由无数个小的物体组成
 *
 * 角色
 * Facade: 外观角色
 * SubSystem:子系统角色
 */

#include <iostream>
using namespace std;

class SystemA {
public:
    void operation() {
        cout << "SystemA :: operation\n";
    }
};

class SystemB {
public:
    void operation() {
        cout << "SystemB :: operation\n";
    }
};

class SystemC {
public:
    void operation() {
        cout << "SystemC :: operation\n";
    }
};


class Facade {
public:
    Facade() {
        _a = new SystemA;
        _b = new SystemB;
        _c = new SystemC;
    }

    ~Facade() {
        delete _a;
        delete _b;
        delete _c;
    }

    void wrapOperation() {
        cout << "Facade :: wrapOperation\n";
        _a->operation();
        _b->operation();
        _c->operation();
    }
private:
    SystemA* _a;
    SystemB* _b;
    SystemC* _c;
};

void client() {
  Facade facade;
  facade.wrapOperation();
}

int main(int agrc, const char* agrv[]) {
    client();
    return 0;
}

