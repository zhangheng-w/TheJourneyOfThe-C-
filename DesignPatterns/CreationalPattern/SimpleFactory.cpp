/*
 * Created by weyiua on 2021/8/2.
 * �򵥹���ģʽ
 *
 * ͨ��һ���������ݲ�ͬ�Ĳ��� ������ͬ�Ķ���
 *
 * ��ɫ
 * Factory��������ɫ
 * Product�������Ʒ��ɫ
 * ConcreteProduct�������Ʒ��ɫ
 */

#include <iostream>
using namespace std;

class Product{
public:
    virtual void printProduct() {}
};

class ProductA : public Product {
public:
    void printProduct() {
        cout << "Product A" << endl;
    }
};

class ProductB : public Product {
public:
    void printProduct() {
        cout << "Product B" << endl;
    }
};

class Factory {
public:
    Product* createProduct(string s) {
        if(s == "A") {
            return new ProductA();
        } else if(s == "B") {
            return new ProductB();
        }
    }
};

int simpleFactoryTest() {
    Factory factory;
    auto a = factory.createProduct("A");
    a->printProduct();
    auto b = factory.createProduct("B");
    b->printProduct();
    delete a;
    delete b;
}

int main(int agrc, const char *agrv[]) {
    simpleFactoryTest();
    return 0;
}
