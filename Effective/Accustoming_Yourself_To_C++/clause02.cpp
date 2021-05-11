/*
by author heng  20-11-21
������const enum inline ���� #define p13

1�����ڵ��������������const�����enum����#define
2���������ƺ����ĺ꣬��ø���inline��������#define
*/

#include <iostream>
using namespace std;

//#define ASPECT_RATIO = 1.653
//const����#define
const double AspectRatio = 1.653;

const char* const authorName = "Effective Book";
//authorName = "df";  


class GamePlays{
public :
    static const int NumTurns = 5;       //��̬��Ա���� int���Ϳ���ֱ�Ӹ�ֵ  
    enum { EnumNumTurns = 5 };           //enum  һ��ö�����͵���ֵ��Ȩ��intʹ��
};                                       //�ɱ����� ������static��Ա������ʽ��ó�ֵ�� ���γ�������

const int GamePlays::NumTurns;           //���ⶨ��

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

const double CostEstimate::FudgeFactor = 12.23; //��������

void CostEstimateTest( ostream &os = cout ) {
    os << "CostEstimate::FudgeFactor=" << CostEstimate::FudgeFactor << endl;
}


int a = 5, b = 0; 
#define CALL_WITH_MAX(a, b) f( (a) > (b) ) ? (a) : (b) )    //CALL_WITH_MAX ���ú���f�Ƚ�a��b��С   //�� ���� ���Բ�������С����

template<typename T>
inline void callWithMax( const T& a, const T& b ) {
    //f(a > b ? a : b);
}

void claaWithMaxTest() {                                    
    /*����
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