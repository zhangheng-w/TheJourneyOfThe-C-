/*
 * Created by weyiua on 2021/9/13.
 */

#include "_Sort.h"
#include <iostream>
using namespace std;

void sortTest() {
    int insertp[15] = {3, 2, 9, 4, 5, 7, 1, 12, 6, 10, 13, 14, 8, 20, 23};
    InsertSort(insertp, 15);
    for(int i : insertp) {
        cout << i << " ";
    }
    cout << endl;

    int shellp[] = {3, 2, 9, 4, 5, 7, 1, 12, 6, 10, 13, 14, 8, 20, 23};
    ShellSort(shellp, 15);
    for(int i : shellp) {
        cout << i << " ";
    }
    cout << endl;

    int heapP[] = {3, 2, 9, 4, 5, 7, 1, 12, 6, 10, 13, 14, 8, 20, 23};
    ShellSort(heapP, 15);
    for(int i : heapP) {
        cout << i << " ";
    }
    cout << endl;

    int mergeP[] = {3, 2, 9, 4, 5, 7, 1, 12, 6, 10, 13, 14, 8, 20, 23};
    ShellSort(mergeP, 15);
    for(int i : mergeP) {
        cout << i << " ";
    }
    cout << endl;

    int quickP[] = {3, 2, 9, 4, 5, 7, 1, 12, 6, 10, 13, 14, 8, 20, 23};
    QuickSort(quickP, 15);
    for(int i : quickP) {
        cout << i << " ";
    }
    cout << endl;
}

int main(int agrc, const char *agrv[]) {
    sortTest();
    return 0;
}