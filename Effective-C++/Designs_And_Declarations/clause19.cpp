/*
by author heng  20-11-28
设计class犹如设计type

1、class的设计就是type的设计。在定义一个新的type之前，请先考虑过本条款覆盖的所有讨论主题
*/


/*

1、新type的对象应该如何被创造和销毁？这会影响到你的class的构造函数和析构函数以及内存分配函数和释放函数
  （operator new， operator new[]，operator delete， operator delete[])的设计，当然前提是你打算撰写它们

2、对象的初始化和对象的赋值该有什么样的差别？这个答案决定你的构造函数和赋值（assignment）操作符的行为，
   以及其间的差异。很重要的识别混淆了“初始化”和“赋值”，因为它们对应于不同的函数调用

3、新type的对象如果被passed by value（以值传递），意味着什么？记住，copy构造函数用来定义一个type的pass-by-value该如何实现

4、什么是新type的“合法值”？对class的成员变量而言，通常只有某些数值集是有效的。那些数值集决定了你的class必须维护和约束的条件，
   也就决定了你的成员函数（特别是构造函数、赋值操作符和所谓的”setter“函数必须进行错误检查工作。它影响函数抛出的异常、以及（极少被使用的）函数异常明细列

...
*/