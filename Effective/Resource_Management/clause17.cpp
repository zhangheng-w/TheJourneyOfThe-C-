/*
by author heng  20-11-27
以独立语句将new p75

1、以独立语句将new 对象存储于（置入）智能指针内，如果不这样做，一旦异常被抛出，有可能导致难以察觉的资源泄漏
*/

#include <memory>
using namespace std;


class Widget {};

int priority() { return 1; }
void processWidge(shared_ptr<Widget> pw, int priority) {}
void test() {
    //processWidge(shared_ptr<Widget>(new Widget()), priority() );
    /*
    if priority函数出现异常， Widget指针将会遗失
    应该先智能指针->
    */
    shared_ptr<Widget> pw(new Widget());
    processWidge(pw, priority() );
}

int main(int agrc, char const *agrv[]){
    test();
    return 0;
}