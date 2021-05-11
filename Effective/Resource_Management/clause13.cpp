/*
by author heng  20-11-26
已对象管理资源 p61

?????????????

<memory>
auto_ptr 智能指针  auto_ptr被销毁时会自动删除它所指物
注意别让auto_ptr同时指向同一个对象

1、为防止资源泄漏，请使用RAII对象，他们在构造函数中获得资源并在析构函数释放资源
2、两个常被使用的RAII class行为分别是tr1::shared_ptr 和 auto_ptr.前者通常是较佳选择，
   因为其copy行为比较直观。若选择auto_ptr，复制动作会使它（被复制物）指向null

*/

#include <memory>
#include <iostream>
using namespace std;

class Investment {

};

Investment* createInvestment() {
    return new Investment();
}

void f() {
    /* Investment* pInv = createInvestment();
    delete pInv; */                                       //手动释放对象

    auto_ptr<Investment> pInv(createInvestment());        //通过auto_ptr的析构函数自动删除pInv

    auto_ptr<Investment> pInv2(pInv);
    //pInv == pInv2;                                      //不能同时指向一个对象-- null -----????

    shared_ptr<Investment> sharedPtrpInv(createInvestment());
    shared_ptr<Investment> sharedPtrpInv2(sharedPtrpInv);
    sharedPtrpInv = sharedPtrpInv2;                       //不会报错   sharedPtrpInv and sharedPtrpInv2 被销毁所指的对象也会被销毁
 
    //auto_ptr<string> aps(new string[10]);               //auto_ptr 析构函数调用的是delete 不是delete[]
}

int main(int agrc, char const *agrv[]) {
    f();
    return 0;
}