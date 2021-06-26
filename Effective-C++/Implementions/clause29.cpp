/*
 * Created  by heng on 2020/12/15.
 *为“异常安全”而努力是值得的
 *
 * 1、异常安全函数即使发生异常么不会泄露资源或允许任何数据结构破环。这样的函数区分三种可能的保证：基本型、强烈型、不抛异常型
 * 2、“强烈保证”往往能够以copy-and-swap实现出了来，但”强烈保证“并非所有函数都可以实现或具备现实意义
 * 3、函数提供的”异常安全保证“通常最高只等鱼其所调用之各个函数的”异常安全保证“中的最弱者
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

    bgImagePtr.reset(new Image(imgSrc));             //以new Image的执行结果 设定bgImagePtr内部指针
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