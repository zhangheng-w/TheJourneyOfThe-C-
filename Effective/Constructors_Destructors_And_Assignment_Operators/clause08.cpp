/*
by author heng  20-11-24
别让异常逃离构造函数 p44


1、析构函数绝对不要吐出异常。如果一个被析构函数调用的函数可能抛出异常
   析构函数应该捕捉异常，然后吞下他们(不传播)或结束程序
2、如果客户需要对某个函数运行期抛出的异常做出反应
   那么class应该提供一个普通函数执行(而非析构函数中)该操作
*/
#include <iostream>
using namespace std;

class DBConnextion {
public :
    static DBConnextion create();
    void close() { cout << "DBconnextion close\n"; }
};

DBConnextion DBConnextion::create() {
    cout << "return DBConnextion object\n";
    return DBConnextion();
}


class DBConn {

public :
    DBConn(const DBConnextion& db) : _db(db) {}
    ~DBConn() { 
        if (!_closed) {
            //_db.close();                                //if close异常 异常就会跑出Destructor
            try{_db.close();}
            catch(const std::exception& e) {
                std::cerr << e.what() << '\n';
                abort();
            }
            cout << "DBConn Default Destructor\n";
        }
    }

    void close() {
        _db.close();
        _closed = true;                                   //双重保险
    }

private :
    DBConnextion _db;
    bool _closed;
};

void dbConnTest() {
    DBConn dbc(DBConnextion::create());
}

int main(int agrc, const char *agrv[]) {
    dbConnTest();
    return 0;
}
