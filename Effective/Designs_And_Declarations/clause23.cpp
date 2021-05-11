/*
by author heng  20-11-30
宁以non-member、non-friend替换member函数

1、宁可那non-member non-friend函数替换member函数。这样可以增加封装性。包裹弹性和技能扩充性
*/

class WebBrowser {
public :
    void clearCache() {}
    void clearHistory() {}
    void removeCookies() {}
 
    void clearEverying() {                    //member函数
        clearCache();
        clearHistory();
        removeCookies();
    }
};

//non-member non-friend函数的选择比member函数好
void clearBrowser(WebBrowser& wb) {          //non-member non-friend函数
    wb.clearCache();
    wb.clearHistory();
    wb.removeCookies();
}

namespace WebBrowserStuff {
    class WebBrowser {};
    void clearBrowser(WebBrowser& wb) {}
}

//可以将一个class写到多个.h文件
//头文件webbrowser.h 针对class WebBrowse自身
namespace WebBrowserStuff {
    //核心机能
    //例如几乎所有客户都需要的non-member函数
}
//头文件webbrowserbookmarks.h 针对class WebBrowse自身
namespace WebBrowserStuff {
    //与书签相关的便利函数
}
//头文件webbrowsercookies.h 针对class WebBrowse自身
namespace WebBrowserStuff {
    //与cookie相关的便利函数
}

int main(int agrc, char const *agrv[]) {
    return 0;
}