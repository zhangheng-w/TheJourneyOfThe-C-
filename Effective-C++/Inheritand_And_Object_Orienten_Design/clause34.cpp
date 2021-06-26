/*
 * Created by he on 2021/2/5.
 * 34. ���ֽӿڼ̳к�ʵ�ּ̳�
 *
 * 1���ӿڼ̳к�ʵ�ּ̳в�ͬ����public�̳��£�derived class���Ǽ̳�base class�Ľӿ�
 * 2��pure virtual����ֻ����ָ���ӿڼ̳�
 * 3�����ӵģ��Ǵ���impure virtual��������ָ���ӿڼ̳м�ȱʡʵ�ּ̳�
 * 4��non-virtual��������ָ���ӿڼ̳��Լ�ǿ����ʵ�ּ̳�
*/

#include <string>
#include <iostream>
using namespace std;

class Shape_ {
public:
    virtual void draw() const = 0;
    virtual void error(const string& msg) { cout << "Shape_ to error->" << msg << "\n"; }
    int objectID() const { return 0; }
};

class Rectangle_ : public Shape_ {
public:
    virtual void draw() const {
        cout << "Rectangle_ to draw\n";
    }
    void error(const string& msg) {
        cout << "Rectangle_ to error->" << msg << "\n";
    }
};
class Ellipse_ : public Shape_ {
public:
    virtual void draw() const {
        cout << "Ellipse_ to draw\n";
    }

    void error(const string& msg) {
        cout << "Ellipse_ to error->" << msg << "\n";
    }
};

void Shape_Test_Ptr() {
    //Shape *ps = new Shape;    //err������ ���麯��������ֱ��
    Shape_* ps_1 = new Rectangle_;
    ps_1->draw();
    ps_1->error("111");
    Shape_* ps_2 = new Ellipse_;
    ps_2->draw();
    ps_2->error("123");
    //ps_1->Shape_::draw();   //����shape::draw
    //ps_2->Shape_::draw();
    ps_1->Shape_::error("this Shape ps_1");  //����base�ĺ���
    ps_2->Shape_::error("this Shape ps_2");
}


class Airport {
public:
    Airport(const string& d) : date(d) {}
    string date;
};
class Airplane {
public:
    //virtual void fly(const Airport& destination){ cout << "this airplane to fly " << destination.date << "\n"; }
    virtual void fly(const Airport& destination) = 0;
    virtual void fly_to_airplan(const Airport& destination) { cout << "this airplane to fly " << destination.date << "\n"; }
protected:
    void defaultFly(const Airport& destination){ cout << "this airplane to fly " << destination.date << "\n"; }

};
class ModelA : public Airplane {
public:
    //virtual void fly(const Airport& destination){ cout << "this airplane-ModelA to fly " << destination.date << "\n"; }
    virtual void fly(const Airport& destination) { defaultFly(destination); Airplane::fly_to_airplan(destination); }
};
class ModelB : public Airplane {
public:
    //virtual void fly(const Airport& destination){ cout << "this airplane-ModelB to fly " << destination.date << "\n"; }
    virtual void fly(const Airport& destination) { defaultFly(destination); Airplane::fly_to_airplan(destination); }
};

void Airplane_test_d() {
    Airport airport("beijing");
    Airplane* modelA = new ModelA();
    modelA->fly(airport);
    Airplane* modelB = new ModelA();
    modelB->fly(airport);
    //modelA->Airplane::fly(airport);
}

int main(int agrc, const char *agrv[]) {
    Shape_Test_Ptr();
    Airplane_test_d();
    return 0;
}