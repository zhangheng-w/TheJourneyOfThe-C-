/*
 * Created by weyiua on 2021/6/23.
 * 45. 运用成员函数模版接受所有兼容类型
 *
 * * 请使用member function template(成员模版函数)生成"可接受所有兼容类型"的函数
 * * 如果你声明member template用于"泛化copy构造"或"泛化assignment操作"，你还是需要声明正常的泛化copy构造和泛化assignment操作符
 */

class Top {};
class Middle : public Top {};
class Bottom : public Middle {};

void testTop() {
    Top* pt1 = new Middle;
    Top* pt2 = new Bottom;
    const Top* pct2 = pt1;
    delete pt1;
    pt1 = nullptr;
    delete pt2;
    pt2 = nullptr;
};

template<typename T>
class SmartPtr {
public:
    //？
    explicit SmartPtr(T* ptr) {}

};

void testSmartPtr() {
    //SmartPtr<Top> pt1 = SmartPtr<Middle>(new Middle);   //err
    //SmartPtr<Top> pt2 = SmartPtr<Bottom>(new Bottom);   //err
    //SmartPtr<const Top> pct2 = pt1;
}

template<typename T>
class SmartPtr_tem {
public:
    template<typename U>
    SmartPtr_tem(const SmartPtr_tem<U>& other) : heldPtr(other.get()) {}
    T* get() const { return heldPtr; }

private:
    T* heldPtr;
};

template<class T>
class Weak {};

template<class T>
class Auto_ptr {};

template<class T>
class Shared_ptr {
public:
    template<class Y>
    explicit Shared_ptr(Y* p) {}
    template<class Y>
    Shared_ptr(Shared_ptr<T> const& r) {}
    template<class Y>
    explicit Shared_ptr(Weak<Y> const& r) {}
    template<class Y>
    explicit Shared_ptr(Auto_ptr<Y>& r) {}

    template<class Y>
    Shared_ptr& operator=(Shared_ptr<T> const& r) {}
    template<class Y>
    Shared_ptr& operator=(Auto_ptr<T>& r) {}
};


int main(int agrc, const char *agrv[]) {
    testTop();
    return 0;
}


