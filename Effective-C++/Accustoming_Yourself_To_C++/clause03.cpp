/*
by author heng  20-11-21
������ʹ��const p17

const_iterator ������ָ���Ԫ�ز��ɱ� const

mutable(�ɱ�)

1����ĳЩ��������Ϊconst�ɰ������������������÷�->
   const����ʩ�����κ��������ڵĶ��󡢺��������������������͡���Ա��������
2����const��non-const��Ա��������ʵ�ʵȼ۵�ʵ��ʱ����non-const�汾����const�汾�ɱ�������ظ���
*/

#include <vector>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

//const���γ���  const��*��߱�ʾָ���ǳ������ұ�ָ�뱾���ǳ���
char gteeting[] = "hello";
char *p = gteeting;                       //non-const pointer, non-const data
const char* p1 = gteeting;                //non-const pointer, const data
char* const p2 = gteeting;                //const pointer, ono-const data
const char* const p3 = gteeting;          //const pointer, const data

void testConstPointer( ostream &os = cout ) {
    os << "p=" << p << "\n"
       << "p1=" << p1 << "\n"
       << "p2=" << p2 << "\n"
       << "p3=" << p3 << "\n";
    p = NULL;
    p1 = nullptr;
    //gteeting = "da";                    //const char* p1----p1ָ�����ǳ���
    //p2 = nullptr;                       //char* const p2---p2��ָ�볣��
    os << "p=" << p << "\n";
}

void f1(const char* c);      //c��ָ��ָ��һ������
void f1(char const* c);      //һ��

/*
stl��iterator������������T* 
iter���䣬����ָ��ͬ�Ķ�����iterָ������ֵ���Ըı�
*/
void iteratorConstTest() {
    vector<int> vec;
    const vector<int>::iterator iter = vec.begin();  //iter �������� T* const
    *iter = 10;
    //++iter;                                        //����
    vector<int>::const_iterator cIter = vec.begin(); //cIter �������� const T*
    //*cIter = 10;                                   //����
    ++cIter;
}


//const��Ա����
class TextBlock {
public :
    TextBlock(const string& str) : text(str) {}
    const char& operator[] ( size_t position ) const { return text[position]; }   //operator[] for cosnt����
    char& operator[] ( size_t position ) { return text[position]; }               //operator[] for non-const����
private:
    string text;
};

void textBlocktest() {
    TextBlock tb("hello");
    const TextBlock ctb("world");
    cout << "tb[0]=" << tb[0] << "\n"
         << "ctb[0]=" << ctb[0] << "\n";
    tb[0] = '1';
    cout << "tb[0]=" << tb[0];
    //ctb[0] = '1';           //ctb��const������Ե��ö�����-const����
}


class CTextBlock {
public:
    CTextBlock(char* c) : _pText(c) {}
    std::size_t length() const;
    char* pText() const { return _pText; }
    bool lengthIsValid() const { return _lengthIsValid; }

private:
    char* _pText;
    mutable size_t _textLength;
    mutable bool _lengthIsValid;
};

size_t CTextBlock::length() const {             //const�������в��ܸ�ֵ  mutable(�ɱ�)��Ա����
    if(!_lengthIsValid) {
        _textLength = strlen(_pText);
        _lengthIsValid = true;
    }
    return _textLength;
}

void cTextBlockTest() {
    char p[] = "1231";
    CTextBlock ctb(p);
    cout << "ctb.pText()=" << ctb.pText() << "\n"
         << "ctb.length()=" << ctb.length() << "\n"
         << "ctb.lengthIsValid()=" << ctb.lengthIsValid();

}

int main(int argc, char const *argv[])
{
    //testConstPointer();
    //textBlocktest();
    cTextBlockTest();
    return 0;
}
