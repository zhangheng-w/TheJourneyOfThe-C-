/*
 * Created by he on 2020/12/27.
 * 32. 确定你的public继承塑模出is-a关系
 *
 * 1、“public继承”意味is-a、适用于base class 身上的每一件事情一定也适用于derived class 身上，因为derived class 也都是一个base class对象
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
    //study(p);   //err p不是学生
}


void error (const string& msg) {}

class Bird {
public:
    virtual void fly() {};
};

class Penguin : public Bird {
public:
    void fly() { error("Attempt to make a penguin fly!")};  //err 企鹅不能飞
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

