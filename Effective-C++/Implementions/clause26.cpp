/*
by author heng  20-12-01
尽可能延后变量定义式的出现时间

<stdexcept>库--->异常抛出的对象的类型

1、尽可能延后变量定义式的出现。这样做可增加程序的清晰度并改善程序效率
*/

#include <string>
#include <stdexcept>

void encrypt(std::string& s) {}

std::string encryptPassword(const std::string& password) {
    using namespace std;
    int  MinimumPasswordLength = 10;
    if(password.length() < MinimumPasswordLength) {
        throw logic_error("Password is to short");    
    }                                                  //有异常抛出,尽量延长变量定义式的出现时间
    /* string encrypted;
    encrypted = password; */                           //赋值
    string encrypted(password);                        //copy构造函数
    encrypt(encrypted);
    return encrypted;
}

class Widget {};

void test() {
    //循环外大体而言比较高效  i越大循环内或许比较好
    //循环外
    Widget w;
    for (int i = 0; i < 100; ++i) {
        //w = 
    }

    //循环内
    for (int i = 0; i < 100; ++i) {
        Widget w();
    }
}

int main(int agrc, char const *agrv[]) {
    return 0;
}