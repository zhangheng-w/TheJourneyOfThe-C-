/*
by author heng  20-11-23
为多态基类声明virtual析构函数 p40

base class      基类
derived class   派生类
override        覆盖

派生类销毁，最深层派生类首先调用析构函数-在依次调用基类的构造函数

virtual函数 
virtual 纯虚函数-抽象类-必须覆盖重写--virtual void virtualFunctions() = 0;

1、polymorphic（带多态性质的）base class 应该声明一个virtual析构函数。如果class
   带有任何一个virtual函数，就应该有一个virtual析构函数
2、class的设计目的不是作为一个base class使用，或不是为了具有多态性质，
   就不应该声明为virtual析构函数
*/

#include <iostream>
#include <string>
using namespace std;

class TimeKeeper {
public :
    TimeKeeper() {}
    virtual ~TimeKeeper() { cout << "TimeKeeper Default Destructor\n"; }

};

class AtomicClock : public TimeKeeper {
public : 
    AtomicClock()  { _name = string("123"); } 
    ~AtomicClock() override { cout << "AtomicClock Default Destructor\n"; }
private :
    string _name;
};
class WaterClock : public TimeKeeper {};
class WristWatch : public TimeKeeper {};

TimeKeeper* getTimeKeeper() {
    return new AtomicClock();
}

void timerKeeperTest() {
    TimeKeeper* ptk = getTimeKeeper();
    delete ptk;                                 //delete ptk  只调用base class析构函数  derived class 可能造成内存泄漏
}                                               //使用virtual关键字  使之成为虚函数


class Point {
public :
    Point(const int& xCoord, const int& yCoord) : _x(xCoord), _y(yCoord) {}
private :
    int _x;
    int _y;

};


class SpecialString : public string {
public :
    SpecialString(const string& s) : _name(s) {}
    ~SpecialString() { cout << "SpecialString Default Destructor\n"; }
private : 
    string _name;
};

void specialStringTest() {
    SpecialString* ps = new SpecialString("Impending Doom");
    string* pss = ps;                         //内存泄漏
    delete pss;                               //string base class destructor non virtual function（string 基类析构函数不是虚函数--不会调用）
}

int main(int agrc, char const *agrv[]) {
    timerKeeperTest();
    specialStringTest();
    return 0;
}