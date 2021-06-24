/*
 * Created by weyiua on 2021/6/21.
 * 44.  将与参数无关的代码抽离template
 *
 * * Template生成的class和多个函数，所以任何template代码都不该与某个构造膨胀的templarte参数产生相依关系
 * * 因非类型模版参数而造成的代码膨胀，往往可消除，做法是以函数参数或class成员变量替换template参数
 * * 因类型参数而造成的代码膨胀，往往可降低，做法是让带有完全相同二进制表述的具现类型共享实现码
 */
#include <iostream>
using namespace std;

template<typename T, size_t n>
class SquareMatrix {
public:
    void invert() {
        cout << "SquareMatrix::invert()\n";
    }
};

int testMatrix() {
    SquareMatrix<double, 10> sm1;
    sm1.invert();
    SquareMatrix<int, 5> sm2;
    sm2.invert();
}



template<typename T>
class SquareMatrixBase {
protected:
    void invert(size_t matrixSize) {
        cout << "SquareMatrixBase::invert()\n";
    }
};

template<typename T, size_t n>
class SquareMatrixDervied : private SquareMatrixBase<T> {
private:
    using SquareMatrixBase<T>::invert;

public:
    void invert() { this->invert(n); }
};

int testMatrixDerived() {
    SquareMatrixDervied<double, 10> sm1;
    sm1.invert();
    SquareMatrixDervied<int, 5> sm2;
    sm2.invert();
}


template<typename T>
class SquareMatrixBase_t {
protected:
    SquareMatrixBase_t(size_t n, T* pMem)
    : size(n), pData(pMem) {}
    void setDataPtr(T* ptr) { pData = ptr; }
private:
    size_t size;
    T* pData;
};

template<typename T, size_t n>
class SquareMatrixDervied_t : private SquareMatrixBase_t<T> {
private:
    //对象很大，应放在heap中
    //T data[n*n];
    T* pData;
    //boost::scoped_array<T> pData;

public:
    SquareMatrixDervied_t() : SquareMatrixBase<T>(n, 0), pData(new T[n*n]){
        //this->setDataPtr(pData.get());
    }
};


int main(int agrc, const char *agrv[]) {
    testMatrix();
    testMatrixDerived();
    return 0;
}



