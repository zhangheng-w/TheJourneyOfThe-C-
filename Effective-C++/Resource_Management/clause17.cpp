/*
by author heng  20-11-27
�Զ�����佫new p75

1���Զ�����佫new ����洢�ڣ����룩����ָ���ڣ��������������һ���쳣���׳����п��ܵ������Բ������Դй©
*/

#include <memory>
using namespace std;


class Widget {};

int priority() { return 1; }
void processWidge(shared_ptr<Widget> pw, int priority) {}
void test() {
    //processWidge(shared_ptr<Widget>(new Widget()), priority() );
    /*
    if priority���������쳣�� Widgetָ�뽫����ʧ
    Ӧ��������ָ��->
    */
    shared_ptr<Widget> pw(new Widget());
    processWidge(pw, priority() );
}

int main(int agrc, char const *agrv[]){
    test();
    return 0;
}