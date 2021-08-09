## ���ģʽ

#### �������ԭ��
1. Single Responsibility Principle����һְ��ԭ��
2. Open Closed Principle������ԭ��
3. Liskov Substitution Principle�������滻ԭ��
4. Law of Demeter�������ط���
5. Interface Segregation Principle���ӿڸ���ԭ��
6. Dependence Inversion Principle����������ԭ��

#### �������ģʽ
1. ������ģʽ
    * �򵥹���ģʽ (SimpleFactory)
        + Factory��������ɫ
        + Product�������Ʒ��ɫ
        + ConcreteProduct�������Ʒ��ɫ
    * ��������ģʽ (Factory)
        + Product�������Ʒ
        + ConcreteProduct�������Ʒ
        + Factory�����󹤳�
        + ConcreteFactory�����幤��
    * ���󹤳�ģʽ (AbstractFactory)
        + AbstractFactory�����󹤳�
        + ConcreteFactory�����幤��
        + AbstractProduct�������Ʒ
        + Product�������Ʒ
    * ������ģʽ (Builder)
        + Builder����������
        + ConcreteBuilder�����彨����
        + Director��ָ����
        + Product����Ʒ��ɫ
    * ����ģʽ (Singleton)
        + Singleton������

2. �ṹ��ģʽ
    * ������ģʽ (Adapter)
        + Target��Ŀ�������
        + Adapter����������
        + Adaptee����������
        + Client���ͻ���
    * �Ž�ģʽ (Bridge)
        + Abstraction��������
        + RefinedAbstraction�����������
        + Implementor��ʵ����ӿ�
        + ConcreteImplementor������ʵ����
    * װ��ģʽ (Decorator)
        + Component: ���󹹼�
        + ConcreteComponent: ���幹��
        + Decorator: ����װ����
        + ConcreteDecorator: ����װ����
    * ���ģʽ (Facade)
        + Facade: ��۽�ɫ
        + SubSystem:��ϵͳ��ɫ
    * ��Ԫģʽ (Flyweight)
        + Flyweight: ������Ԫ��
        + ConcreteFlyweight: ������Ԫ��
        + UnsharedConcreteFlyweight: �ǹ��������Ԫ��
        + FlyweightFactory: ��Ԫ������
    * ����ģʽ (Proxy)
        + Subject: ���������ɫ
        + Proxy: ���������ɫ
        + RealSubject: ��ʵ�����ɫ

3. ��Ϊ��ģʽ
    * ����ģʽ
        + Command: ����������
        + ConcreteCommand: ����������
        + Invoker: ������
        + Receiver: ������
        + Client:�ͻ���
    * �н���ģʽ
        + Mediator: �����н���
        + ConcreteMediator: �����н���
        + Colleague: ����ͬ����
        + ConcreteColleague: ����ͬ����
    * �۲���ģʽ
        + Subject: Ŀ��
        + ConcreteSubject: ����Ŀ��
        + Observer: �۲���
        + ConcreteObserver: ����۲���
    * ״̬ģʽ
        + Context: ������
        + State: ����״̬��
        + ConcreteState: ����״̬��
    * ����ģʽ
        + Context: ������
        + Strategy: ���������
        + ConcreteStrategy: ���������
