/*
 * Created by weyiua on 2021/6/25.
 * 51. 编写new和delete时需固守常规
 *
 * * operator new应该内含一个无穷循序，并在其中尝试分配内存，如果它无法满足内存需求，就该调用new-handler。
 *   它也应该有能力处理0bytes申请，class专属版本则还应该处理"比正确大小更大的申请"
 * * operator delete应该再收到null指针时不做任何事。class专属版本则还应该处理"比正确大小更大申请"
 */

#include <iostream>
using namespace std;

class Base {
public:
    static void* operator new(size_t size) throw(bad_alloc);
    static void operator delete(void* ramwMemory,  size_t size) throw();
};

class Derived : public Base {

};

void* Base::operator new(size_t size) throw(bad_alloc) {
    if(size != sizeof(Base)) {
        return ::operator new(size);
    }
}

void Base::operator delete(void* ramwMemory, size_t size) throw() {
    if(ramwMemory == 0) return ;
    if(size != sizeof(Base)) {
        ::operator delete(ramwMemory);
        return ;
    }
}

void testBase() {

}

int main(int agrc, const char *agrv[]) {
    return 0;
}
