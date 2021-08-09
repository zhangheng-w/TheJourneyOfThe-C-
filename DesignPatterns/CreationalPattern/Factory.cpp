/*
 * Created by weyiua on 2021/8/2.
 * 工厂方法
 * 每个工厂创建不同的产品
 * 调用不同的工厂创建不同的产品
 *
 * 角色
 * Product：抽象产品
 * ConcreteProduct：具体产品
 * Factory：抽象工厂
 * ConcreteFactory：具体工厂
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
