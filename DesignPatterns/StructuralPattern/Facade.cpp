/*
 * Created by weyiua on 2021/8/9.
 * ���ģʽ
 * �����е����ͨ��һ��ϵͳ���
 * ������һ�ۿ�������� ����������С���������
 *
 * ��ɫ
 * Facade: ��۽�ɫ
 * SubSystem:��ϵͳ��ɫ
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

