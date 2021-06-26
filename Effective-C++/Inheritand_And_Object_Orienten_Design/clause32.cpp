/*
 * Created by he on 2020/12/27.
 * 32. ȷ�����public�̳���ģ��is-a��ϵ
 *
 * 1����public�̳С���ζis-a��������base class ���ϵ�ÿһ������һ��Ҳ������derived class ���ϣ���Ϊderived class Ҳ����һ��base class����
*/

#include <iostream>
using namespace std;

class Person {};
class Student : public Person {};

void eat (const Person& person) { cout << "eating---" << endl; }
void study (const Student& student) { cout << "studiing---" << endl; }

void personAndStudentIsEatandStudyTest () {
    Person p;
    Student s;
    cout << "p_eat" << endl;
    eat(p);
    cout << "s_eat" << endl;
    eat(s);
    cout <<  "s_study" << endl;
    study(s);
    cout << "p_study-->err" << endl;
    //study(p);   //err p����ѧ��
}


void error (const string& msg) {}

class Bird {
public:
    virtual void fly() {};
};

class Penguin : public Bird {
public:
    void fly() { error("Attempt to make a penguin fly!")};  //err ��첻�ܷ�
};

class Bird_ {};
class FlyingBrid : public Bird_ {
public:
    virtual void fly() {};
};
class Penguin_ : public Bird_ {};

int main (int agrc, const char *agrv[]) {
    personAndStudentIsEatandStudyTest();
    return 0;
}

