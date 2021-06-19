/*
 * Created by weyiua on 2021/6/20.
 * ���Բ�Ҫ���¶���̳ж�����ȱʡ����ֵ
 *
 * ��̬�ľ�̬�󶨡���̬��
 * ȱʡ����������Ĭ�ϵĲ���ֵ
 *
 * * virtual����ϵ��̬�󶨶�������˼�ǵ���һ��virtual����ʱ������������һ�ݺ���ʵ�ִ��룬ȡ���ڷ������õ��Ǹ�����Ķ�̬����
 *
 * * ���Բ�Ҫ���¶���һ���̳ж�����ȱʡ����ֵ����Ϊȱʡ����ֵ���Ǿ�̬�󶨣���virtual��������������ΨһӦ�ø�д�Ķ�����������ȴ�Ƕ�̬��
 */

#include <iostream>
using namespace std;

class Shape {
public:
    enum ShapeColor {Red, Green, Blue};
    //���麯�� ���඼Ҫ��д�ú���
    virtual void draw(ShapeColor color = Red) const = 0;
};

class Rectangle : public Shape {
public:
    virtual void draw(ShapeColor color = Green) const {
        cout << "Rectangle::draw\t" << color << endl;
    }
};

class Ciricl : public Shape {
public:
    virtual void draw(ShapeColor color) const {
        cout << "Ciricl::draw\t"<< color << endl;
    }
};

void testShape() {
    //ps pc pr ����pointer-to-Shape���ͣ����Ǿ�̬����
    Shape* ps;                   //��̬����ΪShape*
    Shape* pc = new Ciricl;      //��̬����ΪShape*
    Shape* pr = new Rectangle;   //��̬����ΪShape*

    //��̬���;���ָ"��ǰ��ָ���������"
    ps = pc;                //ps�Ķ�̬���������Circle*
    ps = pr;                //ps�Ķ�̬���������Rectangle*

    //virtual����ϵ��̬�󶨶�������˼�ǵ���һ��virtual����ʱ������������һ�ݺ���ʵ�ִ��룬ȡ���ڷ������õ��Ǹ�����Ķ�̬����
    pc->draw(Shape::Red);
    pr->draw(Shape::Red);
    pr->draw();            //ȱʡ����ȡcolor::Red
}

//ͨ��VNI�ַ����virtual����
class ShapeVNI {
public:
    enum ShapeColor {Red, Green, Blue};
    //���麯�� ���඼Ҫ��д�ú���
    void draw(ShapeColor color = Red) const {
        doDraw(color);
    }

private:
    //�����Ĺ����ڴ����
    virtual void doDraw(ShapeColor color) const {}
};

class RectangleVNI : public ShapeVNI {
public:

private:
    //�����ظ�
    virtual void doDraw(ShapeColor color) const { cout << "RectangleVNI::draw\t"<< color << endl; }
};

void testShapeVNI() {
    ShapeVNI *shapeVni = new RectangleVNI;
    shapeVni->draw(ShapeVNI::Blue);
}

int main(int agrc, const char *agrv[]) {
    testShape();
    testShapeVNI();
    return 0;
}



