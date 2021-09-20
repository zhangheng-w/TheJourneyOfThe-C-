/*
 * Created by weyiua on 2021/9/2.
 */

#include "_Vector.h"
#include <iostream>
using namespace std;

void test() {
    int ivec[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Vector vector(ivec, 9, 20);
    cout << "Vector Size :" << vector.sizeVector() << endl;
    vector.printVector();
    vector.insertVector(1, 0);
    cout << "Vector Size :" << vector.sizeVector() << endl;
    vector.printVector();
    vector.deleteVector(10);
    vector.printVector();
    cout << "Vector Size :" << vector.sizeVector() << endl;
    vector.insertVector(1, 100);
    vector.printVector();
    for(int i = 0; i < 10; ++i) {
        vector.deleteVector(1);
    }
    cout << "Vector Size :" << vector.sizeVector() << endl;
    for(int i = 0; i < 10; ++i) {
        vector.insertVector(i+1, i+1);
    }
    vector.printVector();
    cout << "Vector Size :" << vector.sizeVector() << endl;

    int ivecp[] = {1,3,4,2,1,8,3,4,5,9,6,7};
    Vector iv(ivecp, 12, 20);
    iv.printVector();
    sort(iv);
    iv.printVector();
}


int main(int agrc, const char *agrv[]) {
    test();
    return 0;
}

