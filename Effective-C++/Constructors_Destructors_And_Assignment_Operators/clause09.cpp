/*
by author heng  20-11-24
�����ٹ�������������е���virtual���� p48

����base class���캯����ִ�и�����derived class���캯���� ��derived class�ĳ�Ա������δ��ʼ��
����virtual�����½���derived class

1���ڹ���������ڼ䲻Ҫ����virtual��������Ϊ������ôӲ��½���derived class
   (����ǰִ�й��캯���������������ǲ�)
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
    BuyTrabsaction b;    //��������û�е���BuyTransaction���캯��--ͨ��base class constructors
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