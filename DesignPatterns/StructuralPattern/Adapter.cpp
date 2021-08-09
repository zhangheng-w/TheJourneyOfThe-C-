/*
 * Created by weyiua on 2021/8/9.
 * ������ģʽ
 * ��Ϊ��������������������
 *
 * ���������� ����STL�е�shack��queue����deque��������� �ײ㶼��deque
 * ��Ŀ����������߽��� ���������͸���Ը�������
 *
 * �������� c++���ö�̳�ʵ��
 * ��������������䵽ͬһĿ��
 *
 * ��ɫ
 * Target��Ŀ�������
 * Adapter����������
 * Adaptee����������
 * Client���ͻ���
 */

#include <iostream>
using namespace std;

class Adaptee {
public:
    void toAdapteeSpRequest() {
        cout << "Adaptee ToAdapteeSpResquest\n";
    }
};


class Target {
public:
    virtual void request() { cout << "Target :: request\n"; }
};

class Adapter : public Target {
public:
    Adapter(const Adaptee& a) : adaptee(a) {}

    void request() {
        cout << "Adapter :: request\n";
        adaptee.toAdapteeSpRequest();
    }
private:
    Adaptee adaptee;
};

void objectAdapterTest() {
    Adaptee a;
    Adapter adapter(a);
    adapter.request();
}

//�������� ��̳�

class Adapter2 : public Target, Adaptee {
public:
    void request() {
        cout << "Adapter :: request\n";
        Adaptee::toAdapteeSpRequest();
    }
};

void classAdapterTest() {
    Adapter2 adapter2;
    adapter2.request();
}


int main(int agrc, const char *agrv[]) {
    objectAdapterTest();
    classAdapterTest();
    return 0;
}
