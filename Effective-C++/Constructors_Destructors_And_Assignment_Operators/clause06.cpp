/*
by author heng  20-11-23
������ʹ�ñ������Զ����ɵĺ�������Ӧ����ȷ�ܾ� p37

1��Ϊ���ر������Զ������ԣ��ṩ�Ļ��ܣ�����Ӧ�ĳ�Ա��������Ϊprivate���Ҳ���ʵ��
*/

class HomeForSale {

private:
    //˽���Ҳ�ʵ��
    HomeForSale(const HomeForSale&);                     //private--�����������Զ�����Ĭ�Ϻ���
    HomeForSale& operator=(const HomeForSale&);          //����˽�У����ܵ���  ---- û��д������������Ϊû�б�Ҫ�𣬴�Ҷ�ϰ��д������

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
    //Uncopyable u2(u1);                              //����
    //Uncopyable u2 = u1;                             //����
}

class HomeForSaleE : private Uncopyable {
    //ֱ�Ӽ̳л���copy���캯����copy assignment������
};


int main(int argc, char const *argv[]){
    return 0;
}
