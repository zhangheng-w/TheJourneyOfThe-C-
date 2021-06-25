/*
 * Created by weyiua on 2021/6/25.
 * 49. 了解new-handler的行为
 *
 * * set_new_handler允许客户指定一个函数，在内存分配无法获得满足时被调用
 * * Nothrow new是一个颇为局限的工具，因为它只适用于内存分配；后继的构造函数调用还是可能抛出异常
 */
#include <iostream>
using namespace std;


namespace std_1{
    // If you write your own error handler to be called by @c new, it must
    // *  be of this type.
    //typedef指针指向函数
    typedef void (*new_handler)();

    /// Takes a replacement handler as the argument, returns the
    /// previous handler.
    new_handler set_new_handler(new_handler) throw();
}

/*
 *让更多的内存可被使用
 * 安装另一个new-handler
 * 卸载new-handler
 * 抛出bad_alloc(或派生自bad_alloc)的异常
 * 不返回，通常调用abort或exit
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
//static成员必须在class定义式外定义
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
