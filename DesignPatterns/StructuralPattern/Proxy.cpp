/*
 * Created by weyiua on 2021/8/9.
 * ����ģʽ
 * ��Ӵ��� �����м��и��˰���Ϣ����Ŀ��
 *
 * ��ɫ
 * Subject: ���������ɫ
 * Proxy: ���������ɫ
 * RealSubject: ��ʵ�����ɫ
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