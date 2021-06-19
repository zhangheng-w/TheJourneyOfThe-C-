/*
 * Created by weyiua on 2021/6/20.
 * 绝对不要重新定义继承而来的缺省参数值
 *
 * 多态的静态绑定、动态绑定
 * 缺省参数就是有默认的参数值
 *
 * * virtual函数系动态绑定而来，意思是调用一个virtual函数时，究竟调用那一份函数实现代码，取决于发出调用的那个对象的动态类型
 *
 * * 绝对不要重新定义一个继承而来的缺省参数值，因为缺省参数值都是静态绑定，而virtual函数————你唯一应该覆写的东西————却是动态绑定
 */

#include <iostream>
using namespace std;

class Shape {
public:
    enum ShapeColor {Red, Green, Blue};
    //纯虚函数 子类都要重写该函数
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
    //ps pc pr 都是pointer-to-Shape类型，都是静态类型
    Shape* ps;                   //静态类型为Shape*
    Shape* pc = new Ciricl;      //静态类型为Shape*
    Shape* pr = new Rectangle;   //静态类型为Shape*

    //动态类型就是指"当前所指对象的类型"
    ps = pc;                //ps的动态类型如今是Circle*
    ps = pr;                //ps的动态类型如今是Rectangle*

    //virtual函数系动态绑定而来，意思是调用一个virtual函数时，究竟调用那一份函数实现代码，取决于发出调用的那个对象的动态类型
    pc->draw(Shape::Red);
    pr->draw(Shape::Red);
    pr->draw();            //缺省函数取color::Red
}

//通过VNI手法替代virtual函数
class ShapeVNI {
public:
    enum ShapeColor {Red, Green, Blue};
    //纯虚函数 子类都要重写该函数
    void draw(ShapeColor color = Red) const {
        doDraw(color);
    }

private:
    //真正的工作在此完成
    virtual void doDraw(ShapeColor color) const {}
};

class RectangleVNI : public ShapeVNI {
public:

private:
    //避免重复
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



