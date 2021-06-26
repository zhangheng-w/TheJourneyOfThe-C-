/*
by author heng  20-11-23
Ϊ��̬��������virtual�������� p40

base class      ����
derived class   ������
override        ����

���������٣���������������ȵ�����������-�����ε��û���Ĺ��캯��

virtual���� 
virtual ���麯��-������-���븲����д--virtual void virtualFunctions() = 0;

1��polymorphic������̬���ʵģ�base class Ӧ������һ��virtual�������������class
   �����κ�һ��virtual��������Ӧ����һ��virtual��������
2��class�����Ŀ�Ĳ�����Ϊһ��base classʹ�ã�����Ϊ�˾��ж�̬���ʣ�
   �Ͳ�Ӧ������Ϊvirtual��������
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
    delete ptk;                                 //delete ptk  ֻ����base class��������  derived class ��������ڴ�й©
}                                               //ʹ��virtual�ؼ���  ʹ֮��Ϊ�麯��


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
    string* pss = ps;                         //�ڴ�й©
    delete pss;                               //string base class destructor non virtual function��string �����������������麯��--������ã�
}

int main(int agrc, char const *agrv[]) {
    timerKeeperTest();
    specialStringTest();
    return 0;
}