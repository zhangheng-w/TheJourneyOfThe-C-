/*
 * Created by weyiua on 2021/6/21.
 * 43. ѧϰ����ģ�廯�����ڵ�����
 *
 * * ����derived class template��ͨ��"this->"ָ��base class template�ڵĳ�Ա���ƣ�����һ������д����"base class�ʸ����η�"���
 */

#include <iostream>
#include <string>
using namespace std;

class Company {
public:
    //���麯���̳б�����д
    virtual void sendCleartext(const string& msg)  = 0;
    virtual void sendEncrypted(const string& msg) = 0;
};

class CompanyA : public Company {
public:
    void sendCleartext(const string &msg)  {

    }

    void sendEncrypted(const string &msg)  {

    }
};

class CompanyB : public Company {
public:
    void sendCleartext(const string &msg)  {

    }

    void sendEncrypted(const string &msg)  {

    }
};

class MsgInfo {};

template<typename TCompany>
class MsgSender {

public:
    void sendClear(const MsgInfo& info) {
        string msg;
        TCompany c;
        c.sendCleartext(msg);
    }

    void sendSecret(const MsgInfo* info) {

    }
};

class CompanyZ {
public:

    void sendSecret(const MsgInfo* info) {

    }
};

//template�ػ���
template<>
class MsgSender<CompanyZ> {
public:
    void sendSectect(const MsgInfo& info) {

    }
};

template<typename TCompany>
class LoggingMsgSender : public MsgSender<TCompany> {
public:
    using MsgSender<TCompany>::sendClear;
    void sendClearMsg(const MsgInfo& info) {
        //sendClear(info);  //err
        this->sendClear(info);
        MsgSender<TCompany>::sendClear(info);

        sendClear(info);
    }
};

void testLog() {
    //CompanyZ��û��sendClear
    //LoggingMsgSender<CompanyZ> zMsgSender;
    MsgInfo msgInfo;
    //zMsgSender.sendClearMsg(msgInfo);  //err

    LoggingMsgSender<CompanyA> aMsgSender;
    aMsgSender.sendClearMsg(msgInfo);

}


int main(int agrc, const char *agrv[]) {
    testLog();
    return 0;
}
