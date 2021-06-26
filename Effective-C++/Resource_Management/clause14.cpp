/*
by author heng  20-11-26
在资管理类中小心使用copying行为

*/

#include <mutex>
using namespace std;


/* class Lock {
public :
    explicit Lock(mutex* pm) : mutexPtr(pm) { mutexPtr->lock(); }
    ~Lock() { mutexPtr->unlock(); }

private :
    murex* mutexPtr;
}; */