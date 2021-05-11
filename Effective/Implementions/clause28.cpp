/*
by author heng  20-12-07
避免返回handles指向对象内部成分

1、避免返回handles（包括references、指针、迭代器）指向对象内部。遵守这个条款可增加封闭性，
   帮助const成员函数的行为像个const，并将发生“虚吊号码牌”的可能性将至最低。

*/


#include <memory>
#include <iostream>
using namespace std;

class Point {
public:
    Point(int x, int y) : _x(x), _y(y) {}
    void setX(int newVal) { _x  = newVal; }
    void setY(int newVal) { _y  = newVal; }
    int getX() const { return _x; }
    int getY() const { return _y; }

    friend ostream &operator<<(ostream &os, const Point &point);

private:
    int _x;
    int _y;
};

struct RecData {
    RecData(const Point &ulhc, const Point &lrhc) : ulhc(ulhc), lrhc(lrhc) {}

    Point ulhc;
    Point lrhc;
};

ostream &operator<<(ostream &os, const Point &point) {
    os << "Point[_x: " << point._x << ", _y: " << point._y << "]\n";
    return os;
}

class Rectangle {
public:
    Rectangle() {}
    Rectangle(shared_ptr<RecData>& value) : pData(value) {}
    Rectangle(const Point& p1, const Point& p2) {
        pData->lrhc = p1;
        pData->ulhc = p2;
    }
    const Point& upperLeft() const { return pData->ulhc; }
    const Point& lowerRifgt() const { return pData->lrhc; }
    shared_ptr<RecData> getPData() const { return pData; }

    friend ostream &operator<<(ostream &os, const Rectangle &rectangle);

private:
    shared_ptr<RecData> pData;
};

ostream &operator<<(ostream &os, const Rectangle &rectangle) {
    os << "pData: " << rectangle.pData->lrhc << rectangle.pData->ulhc;
    return os;
}


void test() {
    Point coord1(0,0);
    Point coord2(100, 100);
    shared_ptr<RecData> sharedPtr(new RecData(coord1, coord2));
    const Rectangle rec(sharedPtr);
    //rec.lowerRifgt().setX(1000);            //private
    //rec.upperLeft().setY(1000);             //reference 指向private内部可以调用
    cout << coord1;
    cout << rec;
}

class GUIObject {

};

const Rectangle boundingBox(const GUIObject& obj) {
    return Rectangle();
}


void testNullPoint() {
    GUIObject* obj;
    const Point* pUpperLeft = &(boundingBox(*obj).upperLeft());   //函数结束temp被销毁，指向空对象
    cout << pUpperLeft;
}


int main(int agrc, char const *agrv[]) {
    test();
    testNullPoint();
    return 0;
}