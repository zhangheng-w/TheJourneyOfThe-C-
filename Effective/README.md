# Effective C++  
### <span id="head"> 目录 </span>
| 序号 |  条款  | 文件  | 跳转 |
| :---:|  :---:  | :---:  | :---: |
| 第一章 让自己习惯**C++** |  | [Accustomng_Yourself_To_C++](Accustoming_Yourself_To_C++) |  |
|  01  | 视**C++** 为一个语言联邦 |  | [jump](#clause1) |
|  02  | 尽量以**const**，**enum**，**inline**替换 **#define** | [clause02.cpp](Accustoming_Yourself_To_C++/clause02.cpp) | [jump](#clause2) |
|  03  | 尽可能使用**const** | [clause03.cpp](Accustoming_Yourself_To_C++/clause03.cpp) | [jump](#clause3) |
|  04  | 确定对象被使用前已先被初始化 | [clause04.cpp](Accustoming_Yourself_To_C++/clause04.cpp) | [jump](#clause4) |
| 第二章 构造/析构/复制运算 | | [Constructors_Destructors_And_Assignment_Operators](Constructors_Destructors_And_Assignment_Operators) |  |
|  05  | 了解**c++** 默默编写并 调用那些函数 | [clause05.cpp](Constructors_Destructors_And_Assignment_Operators/clause05.cpp) | [jump](#clause5) |
|  06  | 若不想使用编译器自动生成的函数，就应该明确拒绝 | [clause06.cpp](Constructors_Destructors_And_Assignment_Operators/clause06.cpp) | [jump](#clause6) |
|  07  | 为多态基类声明**virtual**析构函数 | [clause07.cpp](Constructors_Destructors_And_Assignment_Operators/clause07.cpp)| [jump](#clause7) |
|  08  | 别让异常逃离析构函数 | [clause08.cpp](Constructors_Destructors_And_Assignment_Operators/clause08.cpp) | [jump](#clause8) |
|  09  | 绝不在构造和析构过程中调用**virtual**函数 | [clause09.cpp](Constructors_Destructors_And_Assignment_Operators/clause09.cpp) | [jump](#clause9) |
|  10  | 令**operator=** 返回一个 **reference to** ***this** | [clause10.cpp](Constructors_Destructors_And_Assignment_Operators/clause10.cpp) | [jump](#clause10) |
|  11  | 在**operator=** 处理“自我赋值” | [clause11.cpp](Constructors_Destructors_And_Assignment_Operators/clause11.cpp) | [jump](#clause11) |
|  12  | 复制对象时勿忘其每一个成分 | [clause12.cpp](Constructors_Destructors_And_Assignment_Operators/clause12.cpp) | [jump](#clause12) |
| 第三章 资源管理 | | [Resource_Management](Resource_Management) |
|  13  | 以对象管理资源 | [clause13.cpp](Resource_Management/clause13.cpp) | [jump](#clause13) |
|  14  | 在资源管理类中小心 **copying**行为 | [clause14.cpp](Resource_Management/clause14.cpp) | [jump](#clause14) |
|  15  | 在资源管理类中提供原始资源的访问 | [clause15.cpp](Resource_Management/clause15.cpp) | [jump](#clause15) |
|  16  | 成对使用 **new**和 **delete**时要采用相同形式 | [clause16.cpp](Resource_Management/clause16.cpp) | [jump](#clause16) |
|  17  | 以独立语句将 **new**对象置入智能指针 | [clause17.cpp](Resource_Management/clause17.cpp) | [jump](#clause17) |
| 第四章 设计与声明 | | [Designs_And_Declarations](Designs_And_Declarations) |
|  18  | 让接口容易被正确利用，不易被使用 | [clause18.cpp](Designs_And_Declarations/clause18.cpp) | [jump](#clause18) |
|  19  | 设计**class**犹如设计**type** | [clause19.cpp](Designs_And_Declarations/clause19.cpp) | [jump](#clause19) |
|  20  | 宁以**pass-by-referance-to-const**替换**pass-by-value** | [clause20.cpp](Designs_And_Declarations/clause20.cpp)| [jump](#clause20) |
|  21  | 必须返回对象时，别妄想返回其**reference** | [clause21.cpp](Designs_And_Declarations/clause21.cpp) | [jump](#clause21) |
|  22  | 将成员变量声明为**private** | [clause22.cpp](Designs_And_Declarations/clause22.cpp) | [jump](#clause22) |
|  23  | 宁以**non-member**、**non-friend**替换**member**函数 | [clause23.cpp](Designs_And_Declarations/clause23.cpp) | [jump](#clause23) |
|  24  | 若所有参数皆需类型转换，请为此采用**non-member**函数 | [clause24.cpp](Designs_And_Declarations/clause24.cpp) | [jump](#clause24) |
|  25  | 考虑写出一个不抛异常的**swap**函数 | [clause25.cpp](Designs_And_Declarations/clause25.cpp) | [jump](#clause25) |
| 第五章 实现 |  | [Implementions](Implementions) | |
|  26  | 尽可能延后变量定义式的出现时间 | [clause26.cpp](Implementions/clause26.cpp) | [jump](#clause26) |
|  27  | 尽量少做转型动作 | [clause27.cpp](Implementions/clause27.cpp) | [jump](#clause27) |
|  28  | 避免返回**handles**指向对象成员部分 | [clause28.cpp](Implementions/clause28.cpp)| [jump](#clause28) |
|  29  | 为“异常安全”而努力是值得的 | [clause29.cpp](Implementions/clause29.cpp) | [jump](#clause29) |
|  30  | 透彻了解**inlining**的里里外外 | [clause30.cpp](Implementions/clause30.cpp) | [jump](#clause30) |
|  31  | 将文件间的编译依存关系将至最低 | [clause31.cpp](Implementions/clause31.cpp) | [jump](#clause31) |
| 第六章 继承与面向对象设计 |  | [Inheritance and Object-Oriented Design](Inheritand_And_Object_Orienten_Design) | |
|  32  | 确定你的**public**继承塑模出**is-a**关系 | [clause32.cpp](Inheritand_And_Object_Orienten_Design/clause32.cpp) | [jump](#clause32) |
|  33  | 避免遮掩继承而来的名称 | [clause33.cpp](Inheritand_And_Object_Orienten_Design/clause33.cpp) | [jump](#clause33) |
|  34  | 区分接口继承和实现继承 | [clause34.cpp](Inheritand_And_Object_Orienten_Design/clause34.cpp)| [jump](#clause34) |
|  35  | 考虑**virtual**函数以外的其他选择 | [clause35.cpp](Inheritand_And_Object_Orienten_Design/clause35.cpp) | [jump](#clause35) |
|  36  | 绝不重新定义继承而来的**non-virtual**函数 | [clause36.cpp](Inheritand_And_Object_Orienten_Design/clause36.cpp) | [jump](#clause36) |
|  37  | 绝不重新定义继承而来的缺省参数值 | [clause37.cpp](Inheritand_And_Object_Orienten_Design/clause37.cpp) | [jump](#clause37) |
|  38  | 通过复合塑模出**has-a**或"根据某物实现处" | [clause38.cpp](Inheritand_And_Object_Orienten_Design/clause38.cpp) | [jump](#clause38) |
|  39  | 明智而审慎地使用**private**继承 | [clause39.cpp](Inheritand_And_Object_Orienten_Design/clause39.cpp) | [jump](#clause39) |
|  40  | 明智而审慎地使用多重继承 | [clause40.cpp](Inheritand_And_Object_Orienten_Design/clause40.cpp) | [jump](#clause40) |
| 第七章 模版和泛型编程 |  | [Template_And_Generic_Programming](Template_And_Generic_Programming) | |
|  41  | 了解隐式接口和编译器多态 | [clause41.cpp](Template_And_Generic_Programming/clause41.cpp) | [jump](#clause41) |
|  42  | 了解**typename**的双重意义 | [clause42,cpp](Template_And_Generic_Programming/clause42.cpp) | [jump](#clause42) |
|  43  | 学习处理模板化基类内的名称 | [clause43.cpp](Template_And_Generic_Programming/clause43.cpp) | [jump](#clause43) |
|  44  | 将与参数无关的代码抽离**templates** | [clause44.cpp](Template_And_Generic_Programming/clause44.cpp) | [jump](#clause44) |
|  45  | 运用成员函数模版接受所有兼容类型 | [clause45.cpp](Template_And_Generic_Programming/clause45.cpp) | [jump](#clause45) |
|  46  | 需要类型转换时请为模版定义非成员函数 | [clause46.cpp](Template_And_Generic_Programming/clause46.cpp) | [jump](#clause46) |
|  47  | 请使用**traits classes**表现类型信息  | [clause47.cpp](Template_And_Generic_Programming/clause47.cpp) | [jump](#clause47) |
|  48  | 认识**template**元编程 | [clause48.cpp](Template_And_Generic_Programming/clause48.cpp) | [jump](#clause48) |
| 第八章 定制**new**和**delete** |  | [Customizing_New_And_Delete](Customizing_New_And_Delete) | |
|  49  | 了解**new-handler**的行为 | [clause49.cpp](Customizing_New_And_Delete/clause49.cpp) | [jump](#clause49) |
|  50  | 了解**new**和**delete**的合理替换时机 | [clause50.cpp](Customizing_New_And_Delete/clause50.cpp) | [jump](#clause50) |
|  51  | 编写**new**和**delete**时需固守常规 | [clause51.cpp](Customizing_New_And_Delete/clause51.cpp)| [jump](#clause51) |
|  52  | 写了**placement new**也要写**placement delete** | [clause52.cpp](Customizing_New_And_Delete/clause52.cpp) | [jump](#clause52) |
| 第九章 杂项讨论 |  | [Miscellany](Miscellany) | |
|  53  | 不要轻忽编译器的警告 | [clause53.cpp](Miscellany/clause53.cpp) | [jump](#clause53) |
|  54  | 在资源管理类中小心**copying**行为 | [clause54.cpp](Miscellany/clause54.cpp) | [jump](#clause54) |
|  55  | 在资源管理类中提供原始资源的访问 | [clause55.cpp](Miscellany/clause55.cpp) | [jump](#clause55) |

### 第一章 让自己习惯C++	
#### <span id="clause1">1、视**C++** 为一个语言联邦 </span>
总结来说分为四个部分
* c，说到底c++仍是以c为基础。区块(blocks)、语句(statements)、预处理(preprocessor)、内置数据类型(built-in data types)、数组(arrays)、指针(pointers)等
* Object-Oriented C++。这部分也就是C With Classes所诉求： classes(包括构造函数和析构函数)、封装(encapsulation)、继承(inheritance)、多态(polymorphism)、virtual函数(动态绑定)等
* Template C++。这是C++的泛型编程部分，也是大多分数程序员经验最少的部分。Template相关考虑与设计已经弥漫整个C++，良好编程守则中"惟template适用"的特殊条款并不罕见
* STL。STL是一个template程序库，看名称也知道，但它是非常特殊的一个。它对容器(containers)、迭代器(iterators)、算法(algorithms)以及函数对象(function
 objects)的规约有极佳的紧密配合与协调，而然template及程序库也可以其他想法建置出来
 
#### <span id="clause2">2、尽量以**const**、**enum**、**inline**替换 **#define** </span>
有了const、enum和inline，我们对预处理器(#define)的需求降低了，但并非完全消除。#include仍然是必需品，而#ifdef/#ifndef也继续扮演控制编译的重要角色
* 对于单纯常量，最好以const对象或enum替换#define
* 对于形似函数的宏(macros)，最好改用inline函数替换#define
 
#### <span id="clause3">3、尽可能使用**const** </span>
const关键字出现在星号左边，表示指被指物是常量；如果出现在星号右边，表示指针只是常量；如果出现在星号两边，表示被指物和指针两者都是常量
* 将某些东西声明为const可以帮助编译器侦测出错误用法。const可被施加于任何作用域内的对象，函数参数、函数返回类型、成员函数本体
* 编译器强制实施bitwise constness，但你编写程序时应该使用"概念上的的常量性"
* 当const和non-const成员函数有着实质等价的实现时，令non-const版本调用const版本可避免代码重复

#### <span id="clause4">4、确定对象被使用前已先被初始化 </span>
* 为 内置型对象进行手工初始化，因为C++不保证初始化它们
* 构造函数最好使用成员初始列，而不要在构造函数本体内使用赋值操作。初值列列出的成员变量，其排列次序应该和它们在class中的声明次序相同
* 为免除"跨编译单元之初始化次序"问题，请以local static对象替换non-local static对象

### 第二章 构造/析构/赋值运算	
#### <span id="clause5">5、了解**C++** 默默编写并调用哪些函数 </span>
* 编译器可以暗自为class创建default构造函数、copy构造函数、析构函数、copy assignment操作符
 
#### <span id="clause6">6、若不想使用编译器自动生成的函数，就该明确拒绝 </span>
为驳回编译器自动提供的机能，可将相应的成员函数声明为private并且不予实现
  
#### <span id="clause7">7、为多态基类声明**virtual**析构函数 </span>
* poymorphic(带多态性质的)base class 应该声明一个virtual析构函数，如果class带有任何virtual函数，它就应该拥有一个virtual析构函数
* class的设计目的如果不是作为base class使用，，或不是为了具备多态性(polymorphically),就不该声明virtual析构函数

#### <span id="clause8">8、别让异常逃离析构函数 </span>
* 析构函数绝对不要吐出任何异常，如果一个被析构函数调用的函数可能抛出异常，析构函数应该捕捉任何异常，然后吞下或结束程序
* 如果客户需要对某个操作函数运行期间抛出的异常做出反应，那么class应该提供一个普通函数(而非在析构函数中)执行该操作

#### <span id="clause9">9、绝不构造和析构过程中调用**virtual**函数 </span>
* 在构造和析构期间不要调用virtual函数，因为这类调用从不下降至derived class(比起当前执行构造函数和析构函数的那层)

#### <span id="clause10">10、令**operator=** 返回一个**reference to *this** </span>
* 令赋值(assignment)操作符返回一个reference to *this

#### <span id="clause11">11、在**operator=** 中处理"自我赋值" </span>
* 确保当对象自我赋值时operator=有良好行为。其中技术包括比较"来源对象"和"目标对象"的地址、精心周到的语句顺序、以及copy-and-swap
* 确定任何函数如果操作一个以上的对象，而其中多个对象是同一个对象时，其行为仍然正确

#### <span id="clause12">12、赋值对象时勿忘其每一个成分 </span>
* copying函数应该确保复制"对象内所有成员变量"及"所有base class成分"
* 不要尝试以某个copying函数实现另一个copying函数。应该将共同机能放进第三和函数中，并由copying函数共同调用

### 第三章 资源管理
#### <span id="clause13">13、以对象管理资源 </span>
获取资源后立刻放进管理对象内
管理对象运用析构函数确保资源被释放
* 为防止资源泄漏，请使用RAII对象，它们在构造函数中获取资源并在析构函数中释放资源
* 两个常被使用RAII class分别是shared_ptr和auto_ptr。前者通常是较佳选择，因为其copy行为比较直观，若选择auto_ptr,复制动作会使它(被复制物)指向null

#### <span id="clause14">14、在资源管理类中小心**coping**行为 </span>
* 复制RAII对象必须一并复制它所管理的资源，所以资源copying行为决定RAII对象的copying行为
* 普遍而常见的RAII class copying行为： 抑制copying、施行应用计数发。不过其他行为也都可能被实现

#### <span id="clause15">15、在资源管理类中提供对原始资源的访问 </span>
* API往往要求访问原始资源，所以每个RAII class应该提供一个"取得其所管理之资源"
* 对原始资源的访问可能经由显式转换或隐式转换。一般而言显式转换比较安全，但隐式转换对客户比较方便

#### <span id="clause16">16、成对使用**new**和**delete**时要采用相同形式 </span>
* 如果你在new表达式中使用[],必须在相应的delete表达式中也使用[]
* 如果你在new表达式中不使用[],一定不要在相应的delete表达式中也使用[]

#### <span id="clause17">17、以独立语句将**new** 对象至于智能指针中 </span>
* 以独立语句将new 对象存储于(置于)智能指针内。如果不这样做，一旦异常被抛出，有可能导致难以察觉的资源泄漏

### 第四章 设计与声明
#### <span id="clause18">18、让接口容易被正确使用，不易被误用 </span>
* 好的接口很容易被正确使用，不容易被误用。你应该在你的所有接口中努力达成这些性质
* "促进正确使用"的办法包括接口的一致性，以及与内置类型的行为兼容
* "阻止误用"的办法包括建立新类型、限制类型上的操作，束缚对象值，以及消除客户的资源管理责任
* shared_ptr支持定制型删除器。这可防反DLL问题，可被用来自动解除互斥锁(mutexes)

#### <span id="clause19">19、设计**class**犹如设计**type** </span>
* 新type的对象应该如何被创建和销毁？ 这会影响到你的class的构造函数和析构函数以及内存分配函数和释放函数(operator new, operator new[], operator delete和operator delete[])
* 对象的初始化和对象的赋值该有什么样的差别？ 构造函数和赋值操作符的行为，别混淆了"初始化"和"赋值"，因为它们对应于不同的函数调用
* 新type的对象如果被passed by value(以值传递), copy构造函数来决定一个type的pass-by-value给如何实现、
* 什么是新type的"合法值"
* 你的新type需要配合某个继承图系
* 你的新type需要什么样的转换
* 什么样的操作符和函数对此新type而言是合理的
* 什么样的标准函数改驳回？那些正是你必须声明为private者
* 谁该用新type的成员
* 什么是新type的"未声明接口"
* 你的新type有多么一般化？
* 你真的需要一个新的type吗？
class的设计就是type的设计，在定义一个新type之前，确认考虑是否包含上述的

#### <span id="clause20">20、宁以 **pass-by-reference-to-const**替换 **pass-by-value** </span>
* 尽量以pass-by-reference-to-const替换pass-by-value。前者通常比较高效，并可避免切割问题
* 以上规则并不适用于内置类型，以及STL的迭代器和函数对象。对它们而言，pass-by-value往往比较适当

#### <span id="clause21">21、必须返回对象时，别妄想返回其**reference** </span>
* 绝不要返回pointer或reference指向一个local stack对象，或返回reference指向一个heap-allocated对象，或返回pointer或reference指向一个local static对象而有可能同时需要多个对象

#### <span id="clause22">22、将成员变量声明为**private** </span>
* 切记将成员变量声明为private。这可赋予客户访问数据的一致性、可细微划分访问控制、允诺约束条件获得保证，并提供class作者以充分的实现弹性
* protected并不比public更具封装性

#### <span id="clause23">23、宁以**non-member**、**non-friend**替换**member**函数 </span>
* 宁可拿non-member non-friend函数替换member函数。这样做可以增加封装性、包裹弹性和机能扩充性

#### <span id="clause24">24、若所有的参数皆需类型转换，请为此采用**non-member** </span>
* 如果你需要为某个函数的所有函数(包含被this指针所指的那个隐喻参数)进行类型转换，那么这个函数必须是个non-member

#### <span id="clause25">25、考虑写出一个不抛弃异常的**swap**函数 </span>
* 当std::swap对你的类型效率不高时，并确定这个函数不抛出异常
* 如果你提供一个member swap，也该提供一个non-member swap用来调用前者。对于class(而非template),也请特化std::swap
* 调用swap时应针对std::swap使用using声明式,然后调用swap并且不带任何"命名空间资格修饰"
* 为"用户定于类型"进行std template全特化是好的，但千万不要尝试在std内加入某些对std而言全新的东西

### 第五章 实现
#### <span id="clause26">26、尽可能延后变量定义式的出现时间 </span>
做法A: 1个构造函数 + 1个析构函数 + n个赋值操作  
做法B: n个构造函数 + n个析构函数  
如果class的一个赋值成本低于一组构造+析构成本，做法A大体而言比较高效。尤其当n值很大的时候。否则做法B或许比较好。  
此外做法A造成名称w的作用域比做法B更大，有时那对程序的可理解性和易维护性造成冲突。因此除非（1）你知道赋值成本比"构造 + 析构"成本低  
（2）你正在处理代码中效率高度敏感的部分，否则你应该使用做法B  
* 尽可能延后变量定义式的出现。这样做可增加程序的清晰度并改善程序效率  

#### <span id="clause27">27、尽量少做转型动作 </span>
c风格的转型动作  
1. (T)expression   将expression转型为T  
2. T(expression)   将expression转型为T  
3. const_cast<T>( expression )  
4. dynamic_cast<T>( expression )  
5. reinterpret_cast<T>( expression )  
6. static_cast<T>( expression )  

- const_cast : 通常被用来将对象的常量性转移（cast away constness）。它也是唯一有此功能的C++-style转型操作符  
- dynamic_cast : 主要用来执行"安全向下转型"，也就是用来决定某对象是否归属继承体系中的某个类型。它是唯一无法由旧式语法执行的动作，也是唯一可能耗费重大运行成本的转型动作  
- reinterpret_cast : 意图执行低级转型，实际动作可能取决于编译器，这也就表达它不可移植。例如将一个pointer to int 转型为一个 int。这一类转型在低级代码以外很少见  
- static_cast : 用来强迫隐式转换， 例如将non-canst对象转为const对象，或将int转为double等等。它也可以用来执行上述多种转换的反向转换。   
例如将void* 指针转为typed指针，将pointer-to-base转为pointer-to-derived。但他无法将const转换为non-const，这一个只有const_cast才办得到  
* 如果可以，尽量避免转型，特别是在注重效率的代码中避免dynamic_cast。如果有个设计需要转型动作，试着发展无需转型的代替设计
* 如果转型是必要的，试着将它隐藏于某个函数背后。客户随后可以调用该函数，而不需要将转型放进他们自己的代码内
* 宁可使用C++-style（新式）转型，不要使用旧式转型。前者跟容易被辨识出来，而且也比较有着分门别类的职掌

#### <span id="clause28">28、避免返回**handles**指向对线内部空间 </span>
这并不意味你绝对不可以让成员函数返回handle。有时候你必须那么做。例如operator[]就允许你"摘采"string和vector的个别元素，
而这些operator[]就是返回reference指向reference指向"容器内的数据"，那些数据会随着容器被销毁而销毁。尽管如此，这样的函数毕竟是例外，不是常态
* 避免返回handles (包括reference、指针、迭代器)指向内部对象。遵守这个条款可增加封装性，帮助const成员函数的行为像个const，并将发生"虚吊号码牌"的可能性将至最低

#### <span id="clause29">29、为"异常安全"而努力是值得的 </span>
1. 不泄露任何资源  
2. 不允许数据破坏

* 异常安全函数即使发生异常也不会泄漏资源或允许任何数据结构败坏。这样的函数区分为三种可能的保证: 基本型、强烈型、不抛异常性
* "强烈保证"往往能够以copy-and-swap实现出来，但"强烈保证"并非对所有函数都可实现或具备现实意义
* 函数提供的"异常安全保证"通常最高只等于其所调用之各个函数的"异常安全保证"中的最弱者

#### <span id="clause30">30、透彻了解**inlining**的里里外外 </span>
* 将大多数inlining限制在小型、被频繁调用的函数身上。这可使日后的调试过程中而二进制升级更容易，也可使潜在的代码膨胀问题最小化，使程序的速度提升机会最大化
* 不要只因为function template出现在头文件，就将它们声明为inline

#### <span id="clause31">31、将文件间的编译依存关系将至最低 </span>
* 如果使用object reference 或 object pointer可以完成任务，就不要使用object ： 你可以只靠一个类型声明式就定义出指向该类型的reference和pointer；但如果定义某类型的object，就需要用到该类型的定义式
* 如果能够；尽量以class声明式替换class定义式：注意，当你声明一个函数而它用到某个class时，你并不需要该class的定义；纵使函数以by value方式传递该类型的参数(返回值)亦然

* 未声明式和定义式提供不同的头文件
* 支持"编译依存性最小化"的一般构想是”相依于声明式，不要相依于定义式。基于此构想的两个手段是Handle class 和 interface class
* 程序库头文件应该以"完全且仅有声明式"的形式存在。这种做法不论是否涉及template都使用

### 第六章 继承与面向对象设计
#### <span id="clause32">32、确定你的**public**继承塑模出**is-a**关系 </span>
* "public继承"意味着is-a。适用于base class身上的每一件情况一定也适用于derived class身上，因为每一个身上derived class对象也都是一个base class对象

#### <span id="clause33">33、避免遮掩继承而来的名称 </span>
* derived class内的名称会遮掩base class内的名称。在public继承下从来没有人希望如此
* 为了让被遮掩的名称再见天日，可使用using声明式或转交函数

#### <span id="clause34">34、区分借口继承和实现继承 </span>
1. 声明non-virtual函数的目的是为了令derived class继承函数的接口及一份强制性实现

* 接口继承和实现继承不同。在public继承之下，derived class总是继承base class的接口
* pure virtual函数只具体指定接口函数
* 简朴的(非纯)impure virtual函数具体指定接口继承及缺省实现继承
* non-virtual函数具体指定接口继承以及强制性实现继承

#### <span id="clause35">35、考虑**virtual**函数以及的其他选择 </span>
1. 使用non-virtual interface(NVI)手法，那么Template Method设计模式的一种特殊形式。它以public non-virtual成员函数包裹较低访问性(private或protected)的virtual函数
2. 将virtual函数替换为"函数指针成员变量"这是Strategy设计模式的某种形式
3. 以function成员变量替换virtual函数，因而允许使用任何可调用物搭配一个兼容于需求的签名式，这是Strategy设计模式的某种形式
4. 将继承体系内的virtual函数替换为另一个继承体系内的virtual函数。这是Strategy设计模式的传统实现手法

* virtual函数的替代方案包括NVI手法及Strategy设计模式的多种形式。NVI手法自身是一个特殊形式的Template Method设计模式
* 将机能从成员函数移到class外部函数，带来的一个缺点是，非成员函数无法访问class的non-public成员
* function对象的行为就像一般函数指针。这样的对象可接纳"与给定之目标签名式兼容"的所有可调用物

#### <span id="clause36">36、绝不重新定义继承而来的**non-virtual**函数 </span>
* 绝对不要重新定义继承而来的non-virtual函数  

#### <span id="clause37">37、绝不重新定义继承而来的缺省参数值 </span>
* 绝对不要重新定义一个继承而来的缺省参数值，因为缺省参数值都是静态绑定，而virtual函数——你唯一应该覆写的东西——却是动态绑定  

#### <span id="clause38">38、通过复合塑模出**has-a**或"根据某物实现出" </span>
* 复合(composition)的意义和public继承完全不同  
* 在应用域(application domain)，复合关系意味is-implemented-in-terms-of(根据某物实现出)  

#### <span id="clause39">39、明智而审慎地使用**private**继承 </span>
* private继承意味is-implemented-in-terms-of(根据某物实现出)。它通常比复合(composition)的级别低。但是当derived class需要访问protected base class的
  成员，或需要重新定义继承而来的virtual函数时，这么设计是合理的  
* 和复合(composition)不同，private继承可以造成empty base最优化。这对致力于"对象尺寸最小化"的程序库开发者而言，可能很重要  

#### <span id="clause40">40、明智而审慎地使用多重继承 </span>
* 多重继承比单一继承复杂。它可能导致新的歧义性，以及对virtual继承的需要。
* virtual继承会增加大小、速度、初始化(及赋值)复杂度等等成本。如果virtual base class不带任何数据，将是最具有实用价值的情况
* 多重继承的确有正当用途。其中一个情节涉及"public继承某个Interface class"和"private继承某个协助实现的class"的两相结合

### 第七章 模版和泛型编程 
#### <span id="clause41">41、了解隐式接口和编译期多态 </span>
* class和template都支持接口(interface)和多态(polymorphism)
* 对class而言接口是显式(explicit),以函数签名为中心。多态则是通过virtual函数发生于运行期
* 对template参数而言，接口是隐式的，奠基于有效的表达式，多态则是通过template具体化和函数重载解析发生于编译器

#### <span id="clause42">42、了解**typename**的双重意义 </span>
* 声明template参数时，关键字class和typename可以互换
* 请使用关键字typename标识嵌套从属类型名称；但不得在base class lists(基类列)
* 或member initialization list(成员出撕裂)内以它作为base class修饰符

#### <span id="clause43">43. 学习处理模板化基类内的名称 </span>
* 可在derived class template内通过"this->"指涉base class template内的成员名称，或籍有一个明白写出的"base class资格修饰符"完成

#### <span id="clause44">44. 将与参数无关的代码抽离**template** </span>
* Template生成的class和多个函数，所以任何template代码都不该与某个构造膨胀的templarte参数产生相依关系
* 因非类型模版参数而造成的代码膨胀，往往可消除，做法是以函数参数或class成员变量替换template参数
* 因类型参数而造成的代码膨胀，往往可降低，做法是让带有完全相同二进制表述的具现类型共享实现码

#### <span id="clause45">45. 运用成员函数模版接受所有兼容类型 </span>
* 请使用member function template(成员模版函数)生成"可接受所有兼容类型"的函数
* 如果你声明member template用于"泛化copy构造"或"泛化assignment操作"，你还是需要声明正常的泛化copy构造和泛化assignment操作符

#### <span id="clause46">46. 需要类型转换时请为模版定义非成员函数 </span>
* 当我编写一个class template，而它所提供之"于此template相关的"函数支持"所以参数之隐式类型转换"时，请将那些函数定义为"class template内部的friend函数"

#### <span id="clause47">47. 请使用**traits class**表现类型信息 </span>
* 迭代器
* Input迭代器
* Output迭代器
* Forward迭代器
* Bidirectional迭代器 可以向前 还可以向后 set map
* Random Access迭代器   常量时间内向前或向后跳跃任意位置 vector string
 

* 建立一组重载函数(身份像劳工)或函数模版(例如 doAdvance)，彼此间的差异只在于各自的traits参数，令每个函数实现码与其接受traits信息相应和
* 建立一个控制函数(身份像工头)或函数模版(例如 advance)， 它调用上述的"劳工函数"并传递traits class所提供的信息


* Traits class使得"类型相关信息"在编译器可用。它们以template和"template 特化"完成实现
* 整合重载技术(overloading)后, traits class有可能在编译期对类型执行if...else测试

#### <span id="clause48">48. 认识**template**元编程 </span>
* Template metaphorgramming(TMP, 模版元编程)可将工作由运行期移往编译期，因而得以实现早期错误侦测和更高的执行效率
* TMP可被用来生成"基于政策选择组合"的客户端定义代码，也可用避免生成对某些特殊类型并不合适的代码

### 第八章 定制**new**和**delete**
#### <span id="clause49">49. 了解**new-handler**的行为 </span>
* set_new_handler允许客户指定一个函数，在内存分配无法获得满足时被调用
* Nothrow new是一个颇为局限的工具，因为它只适用于内存分配；后继的构造函数调用还是可能抛出异常

#### <span id="clause50">50. 了解**new**和**delete**的合理替换时机 </span>
1. 用来检测运用上的错误
2. 为了强化效能
3. 为了收集使用上的统计数据


1. 为了检测运用错误
2. 为了收集动态分配内存之使用统计信息
3. 为了增加分配和归还的速度
4. 为了降低缺省内存管理器打起来的空间额外开销
5. 为了弥补缺省分配器中的非最佳齐位
6. 为了将相关对象成簇集中
7. 为了获得非传统的行为

* 有许多的理由需要写个自定的new和delete，包括改善效能、对heap运用错误进行调试、收集heap的使用信息

#### <span id="clause51">51. 编写**new**和**delete**时需固守常规 </span>

* operator new应该内含一个无穷循序，并在其中尝试分配内存，如果它无法满足内存需求，就该调用new-handler。它也应该有能力处理0bytes申请，class专属版本则还应该处理"比正确大小更大的申请"
* operator delete应该再收到null指针时不做任何事。class专属版本则还应该处理"比正确大小更大申请"

#### <span id="clause52">52. 写了**placement new**也要写**placement delete** </span>
* 当你写一个placement operator new，请确定也写出了对应的placement operator delete。如果没有这样做，你的程序可能会隐微而时断时续的内存泄漏
* 当你声明placement new和placement delete,请确定不要无意识的遮掩了它们的正常版本

### 第九章 杂项讨论
#### <span id="clause53">53. 不要轻忽编译器的警告 </span>
* 严肃对待编译器发出的警告信息。努力在你的编译器的最高(最严苛)警告级别下争取"无任何警告"的荣耀
* 不要过度依赖编译器的报警能力，因为不同的编译器对待事物的态度并不相同。一旦移植到另一个编译器上，你原本依赖的警告信息可能消失

#### <span id="clause54">54. 让自己熟悉包括TR1在内的标准程序库 </span>
* C++标准程序库的主要机能有STL、ioterator、locales组成。并包括C99标准程序库
* TR1添加了智能指针(例如 tr1::shared_ptr)、一般化函数指针(tr1::function)、hash-based容器、正则表达式以及另外10个组件的支持
* TR1自身只是一种规范。为获得TR1提供的好处，你需要一份实物。一个好的实物来源是Boost

#### <span id="clause55">55. 让自己熟悉Boost </span>
* Boost是一个社群，也是一个网站。致力于免费、源码开放、同僚复审的C++程序库开发。Boost在C++标准化过程中扮演深具影响力的角色
* Boost提供许多TR1组件实现品，以及其他许多程序库


#### [返回顶部](#head)