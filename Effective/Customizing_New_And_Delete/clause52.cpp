/*
 * Created by weyiua on 2021/6/25.
 * 52. д��placement newҲҪдplacement delete
 *
 * *����дһ��placement operator new����ȷ��Ҳд���˶�Ӧ��placement operator delete�����û������������ĳ�����ܻ���΢��ʱ��ʱ�����ڴ�й©
 * *��������placement new��placement delete,��ȷ����Ҫ����ʶ�����������ǵ������汾
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
    //��������ʽ��new
    static void* operator new(size_t size, ostream& logStream) throw(bad_alloc);
    //������ʽ��delete
    static void operator delete(void* rewMemory, size_t size) throw();
    static void operator delete(void* rewMemory,  ostream& logStream) throw();
};

//operator new ��������ʽ
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