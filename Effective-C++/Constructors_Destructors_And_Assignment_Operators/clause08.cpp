/*
by author heng  20-11-24
�����쳣���빹�캯�� p44


1�������������Բ�Ҫ�³��쳣�����һ���������������õĺ��������׳��쳣
   ��������Ӧ�ò�׽�쳣��Ȼ����������(������)���������
2������ͻ���Ҫ��ĳ�������������׳����쳣������Ӧ
   ��ôclassӦ���ṩһ����ͨ����ִ��(��������������)�ò���
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
            //_db.close();                                //if close�쳣 �쳣�ͻ��ܳ�Destructor
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
        _closed = true;                                   //˫�ر���
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
