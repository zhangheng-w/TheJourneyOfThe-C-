/*
 * Created by weyiua on 2021/6/25.
 * 51. ��дnew��deleteʱ����س���
 *
 * * operator newӦ���ں�һ������ѭ�򣬲������г��Է����ڴ棬������޷������ڴ����󣬾͸õ���new-handler��
 *   ��ҲӦ������������0bytes���룬classר���汾��Ӧ�ô���"����ȷ��С���������"
 * * operator deleteӦ�����յ�nullָ��ʱ�����κ��¡�classר���汾��Ӧ�ô���"����ȷ��С��������"
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
