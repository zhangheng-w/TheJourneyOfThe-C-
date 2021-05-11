/*
by author heng  20-12-07
���ⷵ��handlesָ������ڲ��ɷ�

1�����ⷵ��handles������references��ָ�롢��������ָ������ڲ������������������ӷ���ԣ�
   ����const��Ա��������Ϊ���const��������������������ơ��Ŀ����Խ�����͡�

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
    //rec.upperLeft().setY(1000);             //reference ָ��private�ڲ����Ե���
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
    const Point* pUpperLeft = &(boundingBox(*obj).upperLeft());   //��������temp�����٣�ָ��ն���
    cout << pUpperLeft;
}


int main(int agrc, char const *agrv[]) {
    test();
    testNullPoint();
    return 0;
}