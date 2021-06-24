/*
 * Created by weyiua on 2021/6/21.
 * 44.  ��������޹صĴ������template
 *
 * * Template���ɵ�class�Ͷ�������������κ�template���붼������ĳ���������͵�templarte��������������ϵ
 * * �������ģ���������ɵĴ������ͣ��������������������Ժ���������class��Ա�����滻template����
 * * �����Ͳ�������ɵĴ������ͣ������ɽ��ͣ��������ô�����ȫ��ͬ�����Ʊ����ľ������͹���ʵ����
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
    //����ܴ�Ӧ����heap��
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



