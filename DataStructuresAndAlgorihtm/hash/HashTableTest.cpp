/*
 * Created by weyiua on 2021/9/5.
 */

#include "_HashTable.h"
#include <iostream>
using namespace std;

int main(int agrc, const char* agrv[]) {
    Hashtable hashtable;
    for(int i = 0; i < 100; ++i) {
        hashtable.insertHashTable(i);
    }

    for(int i = 0; i < 100; ++i) {
        cout << *hashtable.findHashTable(i) << " ";
    }
    return 0;
}

