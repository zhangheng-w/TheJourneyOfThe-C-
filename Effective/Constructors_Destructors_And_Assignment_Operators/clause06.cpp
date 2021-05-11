/*
by author heng  20-11-23
若不想使用编译器自动生成的函数，就应该明确拒绝 p37

1、为驳回编译器自动（暗自）提供的机能，可相应的成员函数生命为private并且不予实现
*/

class HomeForSale {

private:
    //私有且不实现
    HomeForSale(const HomeForSale&);                     //private--编译器不会自动创建默认函数
    HomeForSale& operator=(const HomeForSale&);          //将其私有，不能调用  ---- 没有写函数参数，因为没有必要吗，大家都习惯写出来了

};


class Uncopyable {
public :
    Uncopyable() {}
    ~Uncopyable() {}

private :
    Uncopyable(const Uncopyable& );
    Uncopyable& operator=(const Uncopyable& );
};

void uncopyableTest() {
    Uncopyable u1;
    //Uncopyable u2(u1);                              //报错
    //Uncopyable u2 = u1;                             //报错
}

class HomeForSaleE : private Uncopyable {
    //直接继承基类copy构造函数和copy assignment操作符
};


int main(int argc, char const *argv[]){
    return 0;
}
