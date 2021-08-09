## 设计模式

#### 六大基本原则
1. Single Responsibility Principle：单一职责原则
2. Open Closed Principle：开闭原则
3. Liskov Substitution Principle：里氏替换原则
4. Law of Demeter：迪米特法则
5. Interface Segregation Principle：接口隔离原则
6. Dependence Inversion Principle：依赖倒置原则

#### 三类基本模式
1. 创建型模式
    * 简单工厂模式 (SimpleFactory)
        + Factory：工厂角色
        + Product：抽象产品角色
        + ConcreteProduct：具体产品角色
    * 工厂方法模式 (Factory)
        + Product：抽象产品
        + ConcreteProduct：具体产品
        + Factory：抽象工厂
        + ConcreteFactory：具体工厂
    * 抽象工厂模式 (AbstractFactory)
        + AbstractFactory：抽象工厂
        + ConcreteFactory：具体工厂
        + AbstractProduct：抽象产品
        + Product：具体产品
    * 建造者模式 (Builder)
        + Builder：抽象建造者
        + ConcreteBuilder：具体建造者
        + Director：指挥者
        + Product：产品角色
    * 单例模式 (Singleton)
        + Singleton：单例

2. 结构型模式
    * 适配器模式 (Adapter)
        + Target：目标抽象类
        + Adapter：适配器类
        + Adaptee：适配者类
        + Client：客户类
    * 桥接模式 (Bridge)
        + Abstraction：抽象类
        + RefinedAbstraction：扩充抽象类
        + Implementor：实现类接口
        + ConcreteImplementor：具体实现类
    * 装饰模式 (Decorator)
        + Component: 抽象构件
        + ConcreteComponent: 具体构件
        + Decorator: 抽象装饰类
        + ConcreteDecorator: 具体装饰类
    * 外观模式 (Facade)
        + Facade: 外观角色
        + SubSystem:子系统角色
    * 享元模式 (Flyweight)
        + Flyweight: 抽象享元类
        + ConcreteFlyweight: 具体享元类
        + UnsharedConcreteFlyweight: 非共享具体享元类
        + FlyweightFactory: 享元工厂类
    * 代理模式 (Proxy)
        + Subject: 抽象主题角色
        + Proxy: 代理主题角色
        + RealSubject: 真实主题角色

3. 行为型模式
    * 命令模式
        + Command: 抽象命令类
        + ConcreteCommand: 具体命令类
        + Invoker: 调用者
        + Receiver: 接收者
        + Client:客户类
    * 中介者模式
        + Mediator: 抽象中介者
        + ConcreteMediator: 具体中介者
        + Colleague: 抽象同事类
        + ConcreteColleague: 具体同事类
    * 观察者模式
        + Subject: 目标
        + ConcreteSubject: 具体目标
        + Observer: 观察者
        + ConcreteObserver: 具体观察者
    * 状态模式
        + Context: 环境类
        + State: 抽象状态类
        + ConcreteState: 具体状态类
    * 策略模式
        + Context: 环境类
        + Strategy: 抽象策略类
        + ConcreteStrategy: 具体策略类
