/*
 * Created by weyiua on 2021/9/10.
*/
#include "_Heap.h"
#include <iostream>
using namespace std;

void heapTest() {
    Heap heap(20);
    for(int i = 0; i < 12; ++i) {
        heap.pushHeap(i);
        cout << heap.topHeap() << " ";
    }
    cout << endl;
    int* p = heap.getHeapData();
    for(int i = 0; i < heap.HeapSize(); ++i) {
        cout << p[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < 12; ++i) {
        //ȡ����Ԫ��
        cout << heap.topHeap() << " ";
        //�жӵ�һ��Ԫ�س���
        heap.popHeap();
    }


}


int main(int agrc, const char *agrv[]) {
    heapTest();
    return 0;
}