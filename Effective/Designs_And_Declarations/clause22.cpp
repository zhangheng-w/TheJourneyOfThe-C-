/*
by author heng  20-11-29
将成员变量声明为private

1、切记将成员变量声明为private。这可赋予客户访问数据的一致性、可细微划分访问控制、允许约束条件获得保证，并提供class作者以充分的实现弹性;
2、protected并不比public更具封装性
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