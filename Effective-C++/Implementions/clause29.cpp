/*
 * Created  by heng on 2020/12/15.
 *Ϊ���쳣��ȫ����Ŭ����ֵ�õ�
 *
 * 1���쳣��ȫ������ʹ�����쳣ô����й¶��Դ�������κ����ݽṹ�ƻ��������ĺ����������ֿ��ܵı�֤�������͡�ǿ���͡������쳣��
 * 2����ǿ�ұ�֤�������ܹ���copy-and-swapʵ�ֳ�����������ǿ�ұ�֤���������к���������ʵ�ֻ�߱���ʵ����
 * 3�������ṩ�ġ��쳣��ȫ��֤��ͨ�����ֻ������������֮���������ġ��쳣��ȫ��֤���е�������
*/

#include <iostream>
#include <shared_mutex>
#include <Mutex>
#include <memory>
using namespace std;

class Mutex {

};

class Image {
public:
    Image(istream& img) {}
};

class PrettyMenu_1 {
public:
    void changeBackground(istream& imgSrc) ;

private:
    Mutex mutex;
    Image* bgImage;
    int inageChanges;
    shared_ptr<Image> bgImagePtr;
};

void PrettyMenu_1::changeBackground(istream& imgSrc) {
    //lock(&mutex);
    //Lock ml(&mutex);
    delete bgImage;
    ++inageChanges;
    bgImage = new Image(imgSrc);

    bgImagePtr.reset(new Image(imgSrc));             //��new Image��ִ�н�� �趨bgImagePtr�ڲ�ָ��
    //unlock(&mutex);

}


struct PMImpl {
    shared_ptr<Image> bgImage;
    int imageChanges;
};

class PrettyMenu_2 {
public:
    void changeBackground(istream& imgSrc) ;

private:
    Mutex mutex;
    Image* bgImage;
    int inageChanges;
    shared_ptr<PMImpl> pImpl;
};

void PrettyMenu_2::changeBackground(istream& imgSrc) {
    //lock(&mutex);
    //unlock(&mutex);

    using std::swap;
    //Lock ml(&mutex);
    shared_ptr<PMImpl> pNew(new PMImpl(*pImpl));
    ++pNew->imageChanges;
    swap(pImpl, pNew);

}

int main(int agrc, char const *agrv[]) {
    return 0;
}