/*
 * Created by weyiua on 2021/6/25.
 * 53. ��Ҫ����������ľ���
 *
 * * ����Դ������������ľ�����Ϣ��Ŭ������ı����������(���Ͽ�)���漶������ȡ"���κξ���"����ҫ
 * * ��Ҫ���������������ı�����������Ϊ��ͬ�ı������Դ������̬�Ȳ�����ͬ��һ����ֲ����һ���������ϣ���ԭ�������ľ�����Ϣ������ʧ
 */

class B {
public:
    virtual void f() const {}
};

class D : public B {
    //virtual void f() {}
    virtual void f() const {}
};

int main(int agrc, const char *agrv[]) {
    return 0;
}

