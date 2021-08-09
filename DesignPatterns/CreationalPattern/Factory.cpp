/*
 * Created by weyiua on 2021/8/2.
 * ��������
 * ÿ������������ͬ�Ĳ�Ʒ
 * ���ò�ͬ�Ĺ���������ͬ�Ĳ�Ʒ
 *
 * ��ɫ
 * Product�������Ʒ
 * ConcreteProduct�������Ʒ
 * Factory�����󹤳�
 * ConcreteFactory�����幤��
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

class Factroy{
public:
    virtual Product* create() { cout << "create : "; }
};

class FactroyA : public Factroy {
public:
    Product* create() {
        Factroy::create();
        return new ProductA();
    }
};

class FactroyB : public Factroy {
public:
    Product* create() {
        Factroy::create();
        return new ProductB();
    }
};

void factoryTest() {
    Factroy *factroy = new FactroyA;
    Product *pa = factroy->create();
    pa->printProduct();
    delete factroy;
    factroy = new FactroyB;
    Product *pb = factroy->create();
    pb->printProduct();
    delete pa;
    delete pb;
    delete factroy;
}

int main(int agrc, const char* agrv[]) {
    factoryTest();
    return 0;
}
