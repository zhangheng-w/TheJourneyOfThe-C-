/*
by author heng  20-11-25
���ƶ���ʱ������ÿһ���ɷ� p57

1��copying����Ӧ��ȷ�����ơ������ڵ����г�Ա��������������base class�ɷ֡�
2����Ҫ������ĳ��copying����ʵ����һ��copying����Ӧ�ý���ͬ���ܷŵ������������У���������copying������ͬ���� --- ???
*/

#include <string>
#include <iostream>
using namespace std;


class Date {
public :
    Date() {}
    Date(const string& month) : _month(month) {}
    bool operator==(const Date& rhs) {
        return _month == rhs._month;
    }

private : 
    string _month;
};

void logCall(const string& funcName);
class Customer {
public :
    Customer() {}
    Customer(const string& name, const Date& lastTransaction) : _name(name), _lastTransaction(lastTransaction) { logCall("Customer copy constructor\n"); }
    Customer(const Customer& rhs) : _name(rhs._name), _lastTransaction(rhs._lastTransaction) { logCall("Customer copy constructor\n"); }
    Customer& operator=(const Customer& rhs) {
        logCall("Customer copy assignment operator\n");
        if(this == &rhs) return *this;
        _name = rhs._name;
        _lastTransaction = rhs._lastTransaction;    //
        return *this;
    }
    bool operator==(const Customer& rhs) {
        return _name == rhs._name && _lastTransaction == rhs._lastTransaction;
    }

//��Ա�����ı䣬 copy constructors��copy assignment������Ҳ����Ÿı�
private :
    string _name;
    Date _lastTransaction;
};



class PriorityCustomer : public Customer {

public :
    PriorityCustomer() {}
    PriorityCustomer(const string& name, const Date& lastTransaction, const int& priority) : Customer(name, lastTransaction), _priority(priority) { logCall("PriorityCustomer copy constructor\n"); }
    PriorityCustomer(const PriorityCustomer& rhs) : Customer(rhs), _priority(rhs._priority) { logCall("PriorityCustomer copy constructor\n"); }
    PriorityCustomer& operator=(const PriorityCustomer& rhs) {
        logCall("PriorityCustomer copy assignment operator\n");
        if(&rhs == this) return *this;
        Customer::operator=(rhs);
        _priority = rhs._priority;
        return *this;
    }

    bool operator==(const PriorityCustomer& rhs) {
        return Customer::operator==(rhs) && rhs._priority == _priority;
    }
private :
    int _priority;
};


void logCall(const string& funcName) {
    cout << funcName;
}

void customerTest() {
    Date d("12");
    Customer cOne("Lis", d);
    Customer cTwo = cOne;

    PriorityCustomer pOne("ois", d, 10);
    PriorityCustomer pTwo = pOne;
    cout << (cOne == cTwo) << '\n';
    cout << (pOne == pTwo) << '\n';

}

int main(int agrc, char const *agrv[]) {
    customerTest();
    return 0;
}