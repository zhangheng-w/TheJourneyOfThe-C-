/*
by author heng  20-11-30
����non-member��non-friend�滻member����

1��������non-member non-friend�����滻member�����������������ӷ�װ�ԡ��������Ժͼ���������
*/

class WebBrowser {
public :
    void clearCache() {}
    void clearHistory() {}
    void removeCookies() {}
 
    void clearEverying() {                    //member����
        clearCache();
        clearHistory();
        removeCookies();
    }
};

//non-member non-friend������ѡ���member������
void clearBrowser(WebBrowser& wb) {          //non-member non-friend����
    wb.clearCache();
    wb.clearHistory();
    wb.removeCookies();
}

namespace WebBrowserStuff {
    class WebBrowser {};
    void clearBrowser(WebBrowser& wb) {}
}

//���Խ�һ��classд�����.h�ļ�
//ͷ�ļ�webbrowser.h ���class WebBrowse����
namespace WebBrowserStuff {
    //���Ļ���
    //���缸�����пͻ�����Ҫ��non-member����
}
//ͷ�ļ�webbrowserbookmarks.h ���class WebBrowse����
namespace WebBrowserStuff {
    //����ǩ��صı�������
}
//ͷ�ļ�webbrowsercookies.h ���class WebBrowse����
namespace WebBrowserStuff {
    //��cookie��صı�������
}

int main(int agrc, char const *agrv[]) {
    return 0;
}