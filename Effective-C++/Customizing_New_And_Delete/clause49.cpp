/*
 * Created by weyiua on 2021/6/25.
 * 49. �˽�new-handler����Ϊ
 *
 * * set_new_handler����ͻ�ָ��һ�����������ڴ�����޷��������ʱ������
 * * Nothrow new��һ����Ϊ���޵Ĺ��ߣ���Ϊ��ֻ�������ڴ���䣻��̵Ĺ��캯�����û��ǿ����׳��쳣
 */
#include <iostream>
using namespace std;


namespace std_1{
    // If you write your own error handler to be called by @c new, it must
    // *  be of this type.
    //typedefָ��ָ����
    typedef void (*new_handler)();

    /// Takes a replacement handler as the argument, returns the
    /// previous handler.
    new_handler set_new_handler(new_handler) throw();
}

/*
 *�ø�����ڴ�ɱ�ʹ��
 * ��װ��һ��new-handler
 * ж��new-handler
 * �׳�bad_alloc(��������bad_alloc)���쳣
 * �����أ�ͨ������abort��exit
 */

void outOfMem() {
    cerr << "Unable to satisfty request for memory\n";
    abort();
}

void test_new_handler() {
    std::set_new_handler(outOfMem);
    int* pBigDataArray = new int[100000000000L];
}

class X {
public:
    static void outOfMem() {
        cerr << "Unable to satisfty request for memory\n";
        abort();
    }
};

class Y {
public:
    static void outOfMem() {
        cerr << "Unable to satisfty request for memory\n";
        abort();
    }
};

void test_Class_new_handler() {
    X *p1 = new X;
    Y *p2 = new Y;
}

class Widget {
public:
    static std::new_handler set_new_hander(std::new_handler p) throw();
    static void* operator new(size_t size) throw(bad_alloc);

private:
    static new_handler currentHandler;
};
//static��Ա������class����ʽ�ⶨ��
std::new_handler Widget::currentHandler = 0;

new_handler Widget::set_new_hander(std::new_handler p) throw() {
    new_handler oldHandler = currentHandler;
    currentHandler = p;
    return oldHandler;
}


class NewHandlerHolder {
public:
    explicit NewHandlerHolder(new_handler nh) : handler(nh) {}

    virtual ~NewHandlerHolder() {
        set_new_handler(handler);
    }

private:
    new_handler handler;

    NewHandlerHolder(const NewHandlerHolder&);
    NewHandlerHolder& operator=(const NewHandlerHolder&);
};

void* Widget::operator new(size_t size) throw(bad_alloc) {
    NewHandlerHolder h(set_new_hander(currentHandler));
    return ::operator new(size);
}

void testWidget_new() {
    Widget::set_new_hander(outOfMem);
    Widget* pw1 = new Widget;
    string* s1 = new string;
    Widget::set_new_hander(0);
    Widget* pw2 = new Widget;
}

int main(int agrc, const char *agrv[]) {
    test_new_handler();
    test_Class_new_handler();
    testWidget_new();
    return 0;
}
