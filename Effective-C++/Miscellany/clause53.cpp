/*
 * Created by weyiua on 2021/6/25.
 * 53. 不要轻忽编译器的警告
 *
 * * 严肃对待编译器发出的警告信息。努力在你的编译器的最高(最严苛)警告级别下争取"无任何警告"的荣耀
 * * 不要过度依赖编译器的报警能力，因为不同的编译器对待事物的态度并不相同。一旦移植到另一个编译器上，你原本依赖的警告信息可能消失
 */

class B {
public:
    virtual void f() const {}
};

class D : public B {
    //virtual void f() {}
    virtual void f() const {}
};

int main(int agrc, const char *agrv[]) {
    return 0;
}

