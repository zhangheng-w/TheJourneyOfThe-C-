/*
by author heng  20-11-24
绝不再构造和析构过程中调用virtual函数 p48

由于base class构造函数的执行更早于derived class构造函数， 当derived class的成员变量尚未初始化
调用virtual函数下降至derived class

1、在构造和析构期间不要调用virtual函数，因为这类调用从不下降至derived class
   (比起当前执行构造函数和析构函数的那层)
*/

#include <iostream>
#include <string>
using namespace std;


//virtual
class TransactionVirtual {
public :
    TransactionVirtual() { 
        //init();
        logTransaction(); 
    }
    virtual void logTransaction() const = 0;

private :
    void init() { logTransaction(); }
};

void TransactionVirtual::logTransaction() const {
    cout << "TransactionVirtual is logTransaction\n";
}

class BuyTrabsaction : public TransactionVirtual {
public :
    virtual void logTransaction() const { cout << "BuyTransaction is logTransaction\n"; }
};

class ShellTrabsaction : public TransactionVirtual {
public :
    virtual void logTransaction() const { cout << "ShellTransaction is logTransaction\n"; }
};

void Transaction_test() {
    BuyTrabsaction b;    //函数根本没有调用BuyTransaction构造函数--通过base class constructors
    ShellTrabsaction s;
}


//explicit
class TransactionExplicit {
public :
    explicit TransactionExplicit(const string& logInfo) { logTransaction(logInfo); }
    void logTransaction(const string& logInfo) const;
};

int main(int agec, char const *agrv[]) {
    Transaction_test();
    return 0;
}