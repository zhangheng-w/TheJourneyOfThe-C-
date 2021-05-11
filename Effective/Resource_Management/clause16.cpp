/*
by author heng  20-11-27
成对使用new和delete时要采用相同形式

1、如果你在new表达式中使用[]，必须在相应的delete表达式中也使用[]
   如果你在new表达式中不使用[]，一定不要在delete表达式中使用[]
*/
#include <string>
using namespace std;

void test() {
    string* stringArray = new string[10];
    //delete stringArray;       //err
    delete[] stringArray; 

    //成对使用，类型相同
    string* stringPtr1 = new string;
    string* stringPtr2 = new string[100];
    delete stringPtr1;
    delete[] stringPtr2;

    //最好不要对数组形式做typedef动作
    typedef string AddressLine[4];
    string* ptr = new AddressLine;
    delete[] ptr;
}

int main(int agrc, char const *agrv[]) {
    test();
    return 0;
}
