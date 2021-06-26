/*
 * Created by weyiua on 2021/6/25.
 * 52. 写了placement new也要写placement delete
 *
 * *当你写一个placement operator new，请确定也写出了对应的placement operator delete。如果没有这样做，你的程序可能会隐微而时断时续的内存泄漏
 * *当你声明placement new和placement delete,请确定不要无意识的遮掩了它们的正常版本
 */

#include <iostream>
using namespace std;

/*
void* operator new(size_t) throw(bad_alloc);

void operator delete(void* rewMemory) throw();
void operator delete(void* rewMemory, size_t size) throw();
*/



class Wight {
public:
    //非正常形式的new
    static void* operator new(size_t size, ostream& logStream) throw(bad_alloc);
    //正常形式的delete
    static void operator delete(void* rewMemory, size_t size) throw();
    static void operator delete(void* rewMemory,  ostream& logStream) throw();
};

//operator new 的三种形式
void* operator new(size_t size) throw(bad_alloc);            //narmal new
void* operator new(size_t size, void*) throw();              //placement new
void* operator new(size_t size, const nothrow_t&) throw();   //nothrow new

class StandardNewDeleteFroms {
public:
    //narmal new
    static void* operator new(size_t size) throw(bad_alloc) {
        return ::operator new(size);
    }
    static void operator delete (void* rewMemory) throw() {
        ::operator delete (rewMemory);
        return;
    }

    //placement new
    static void* operator new(size_t size, const nothrow_t& nt) throw(bad_alloc) {
        return ::operator new(size, nt);
    }
    static void operator delete (void* rewMemory, const nothrow_t& nt) throw() {
        ::operator delete (rewMemory, nt);
        return;
    }

    //nothrow new
    static void* operator new(size_t size, void* ptr) throw(bad_alloc) {
        return ::operator new(size, ptr);
    }
    static void operator delete (void* rewMemory, void* ptr) throw() {
        ::operator delete(rewMemory, ptr);
        return;
    }
};

int main(int agrc, const char *agrv[]) {
    return 0;
}