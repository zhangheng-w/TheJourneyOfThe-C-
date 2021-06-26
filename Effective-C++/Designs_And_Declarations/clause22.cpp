/*
by author heng  20-11-29
����Ա��������Ϊprivate

1���мǽ���Ա��������Ϊprivate����ɸ���ͻ��������ݵ�һ���ԡ���ϸ΢���ַ��ʿ��ơ�����Լ��������ñ�֤�����ṩclass�����Գ�ֵ�ʵ�ֵ���;
2��protected������public���߷�װ��
*/
#include <string>
#include <memory>
#include <iostream>
using namespace std;

class WebBrowser {
public:
    //getter And setter
    int getReadOnly() const { return readOnly; }
    void setReadOnly(int value) { readOnly = value; }
    int getWriteOnly() const { return writeOnly; }
    void setWriteOnly(int value) { writeOnly = value; }

private:
    int noAccess;
    int readOnly;
    int readWrite;
    int writeOnly;

    friend ostream &operator<<(ostream &out, const WebBrowser &w) {
        out << w.noAccess << " "
            << w.readOnly << " "
            << w.readWrite << " "
            << w.writeOnly << endl;
        return out;
    }
};

void webBrowserTest() {
    WebBrowser w;
    w.setReadOnly(110);
    w.setWriteOnly(011);
    cout << w;
}

int main(int agrc, char const *agrv[]) {
    webBrowserTest();
    return 0;
}