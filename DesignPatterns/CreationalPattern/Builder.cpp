/*
 * Created by weyiua on 2021/8/2.
 * ������ģʽ
 * ��ͬ�Ľ����߽��첻ͬ�Ķ���
 * ���粻ͬ�����ʦ�в�ͬ�ķ�񣬶�����һ��
 *
 * ͨ����ͬ�Ľ����߽��첻ͬ��
 * ���൱��ʳ���в�ͬ���ײͣ� ����ͬ���ײ;��ǲ�ͬ��ʳ��
 *
 * ��ɫ
 * Builder����������
 * ConcreteBuilder�����彨����
 * Director��ָ����
 * Product����Ʒ��ɫ
 */


#include <iostream>
using namespace std;



class Meal {
public:
    Meal() {}
    Meal(const string &drink, const string &food) : _drink(drink), _food(food) {}

    const string &getDrink() const {
        return _drink;
    }

    void setDrink(const string &drink) {
        _drink = drink;
    }

    const string &getFood() const {
        return _food;
    }

    void setFood(const string &food) {
        _food = food;
    }

    friend ostream &operator<<(ostream &os, const Meal &meal);


private:
    string _drink;
    string _food;
};

ostream &operator<<(ostream &os, const Meal &meal) {
    os << "_drink: " << meal._drink << " _food: " << meal._food;
    return os;
}

class MealBulider {
public:
    virtual void builderDrink() {}
    virtual void builderDood() {}
    const Meal &getMeal() const { return _meal; }

protected:
    Meal _meal;
};

class MealBuilder1 : public MealBulider {
public:
    void builderDrink() { _meal.setDrink("Cola"); }
    void builderDood() { _meal.setFood("Fried chicken"); }
};

class MealBuilder2 : public MealBulider {
public:
    void builderDrink() { _meal.setDrink("Orange juice"); }
    void builderDood() { _meal.setFood("Hamburger"); }
};

class KFC{
public:

    void setMe(MealBulider* me) {
        _me = me;
    }

    void construct() {
        _me->builderDood();
        _me->builderDrink();
        cout << _me->getMeal() << endl;
    }

private:
    MealBulider* _me;
};


void BuilderTest() {
    MealBuilder1 ml;
    KFC kfc;
    kfc.setMe(&ml);
    kfc.construct();
    MealBuilder2 m2;
    kfc.setMe(&m2);
    kfc.construct();
}

int main(int agrc, const char *agrv[]) {
    BuilderTest();
    return 0;
}
