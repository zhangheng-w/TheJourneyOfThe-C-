/*
by author heng  20-11-21
尽量用const enum inline 代替 #define p13

1、对于单纯常量，最好以const对象或enum代替#define
2、对于形似函数的宏，最好改用inline函数代替#define
*/

#include <iostream>
using namespace std;

//#define ASPECT_RATIO = 1.653
//const代替#define
const double AspectRatio = 1.653;

const char* const authorName = "Effective Book";
//authorName = "df";  


class GamePlays{
public :
    static const int NumTurns = 5;       //静态成员声明 int类型可以直接赋值  
    enum { EnumNumTurns = 5 };           //enum  一个枚举类型的数值可权当int使用
};                                       //旧编译器 不允许static成员在声明式获得初值， 整形常量可以

const int GamePlays::NumTurns;           //类外定义

void GamePlaysTest( ostream &os = cout ) {
    GamePlays gamepleys;
    os << "GamePlays::NumTurns=" << GamePlays::NumTurns 
       <<  "GamePlays::enum(EnumNumTurns)="  << gamepleys.EnumNumTurns
       << endl;
}


class CostEstimate {
public :
    static const double FudgeFactor;
};

const double CostEstimate::FudgeFactor = 12.23; //常量定义

void CostEstimateTest( ostream &os = cout ) {
    os << "CostEstimate::FudgeFactor=" << CostEstimate::FudgeFactor << endl;
}


int a = 5, b = 0; 
#define CALL_WITH_MAX(a, b) f( (a) > (b) ) ? (a) : (b) )    //CALL_WITH_MAX 调用函数f比较a，b大小   //宏 函数 所以参数都加小括号

template<typename T>
inline void callWithMax( const T& a, const T& b ) {
    //f(a > b ? a : b);
}

void claaWithMaxTest() {                                    
    /*报错
    CALL_WITH_MAX( ++a, b );
    CALL_WITH_MAX( ++a, b+10 );
    */
    callWithMax(10, 11);
}


int main( int argc, char const *argv[] )
{
    cout << AspectRatio << endl;
    GamePlaysTest();
    CostEstimateTest();
    claaWithMaxTest();
    return 0;
}