/*
 * Created by weyiua on 2021/9/2.
 */

#include "_Stack.h"
#include <iostream>
using namespace std;

void test() {
    int ivec[] = {1, 2, 3};
    Stack stack(ivec, 3, 10);
    stack.printStack();
    cout << stack.topStack() << endl;
    stack.popStack();
    cout << stack.topStack() << endl;
    stack.pushStack(10);
    cout << stack.topStack() << endl;
    stack.printStack();
    cout << stack.sizeStack();
}

int main(int agrc, const char *agrv[]) {
    test();
    return 0;
}