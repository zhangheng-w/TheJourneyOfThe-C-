/*
 * Created by weyiua on 2021/8/31.
 */

#include "_List.h"
#include <iostream>
using namespace std;

void test() {
    int ivec[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    List list(ivec, 10);
    cout << "List size: " << list.sizeList() << endl;
    list.printList();
    list.insertList(100, 6);
    list.printList();
    cout << "List size: " << list.sizeList() << endl;
    list.deleteList(6);
    cout << "List size: " << list.sizeList() << endl;
    list.printList();
    cout << list.beginListValue() << endl;
    cout << list.endListValue() << endl;
    //list.destroyList();
    cout << "List size: " << list.sizeList() << endl;
    for(int i = 0; i < 10 && !list.emtpyList(); ++i) {
        list.printList();
        list.deleteList(1);
    }
    cout << "List size: " << list.sizeList() << endl;
    for(int i = 0; i < 10; ++i) {
        list.insertList(i+1, i + 1);
    }

    list.printList();
    reverseList(list).printList();

    int l[] = {1, 3, 5, 6, 7, 8};
    int r[] = {2, 4, 9, 10, 12, 14};
    List l1(l, 6);
    List r1(r, 6);
    List listt = mergeList(l1, r1);
    listt.printList();
    cout << "list size: " << listt.getListSize();

}


int main(int agrc, const char *agrv[]) {
    test();
    return 0;
}

