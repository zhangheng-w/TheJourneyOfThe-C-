/*
 * Created by weyiua on 2021/6/19.
 * 36. �������¶���̳ж�����non-virtual����
 * * ������B�����ÿһ���£�Ҳ������D������Ϊÿһ��D������һ��B����
 * * B��derived classһ����̳�mf�Ľӿں�ʵ�֣���Ϊmf��B��һ��non-virtual����
 *
 * ���Բ�Ҫ���¶���̳ж�����non-virtual����
 */

#include <iostream>
using namespace std;

class B {
public:
    void mf() { cout << "B::mf()\n"; }
};

class D : public B {

    void mf() { cout << "D::mf()\n"; }
};

void testOne() {
    D x;
    B* pb = &x;
    pb->mf();
    D* pd = &x;
    //pd->mf(); err BD��������non-virtual����mf ��ɱ���
}

//public�̳���ζis-a(��һ��)�Ĺ�ϵ

int main(int agrc, const char *agrv[]) {
    testOne();
    return 0;
}