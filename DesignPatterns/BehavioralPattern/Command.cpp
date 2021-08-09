/*
 * Created by weyiua on 2021/8/9.
 * 命令模式
 * 通过不同的命令使之不同的操作
 *
 * 角色
 * Command: 抽象命令类
 * ConcreteCommand: 具体命令类
 * Invoker: 调用者
 * Receiver: 接收者
 * Client:客户类
 */

#include <iostream>
using namespace std;

class Receiver {
public:
    void action() {
        cout << "Receiver :: action\n";
    }
};

class Command {
public:
    virtual void execute() {
        cout << "Command :: execute\n";
    }
};

class ConcteteCommand : public Command{
public:
    ConcteteCommand(Receiver* r) : _receiver(r) {

    }

    void execute() {
        cout << "ConcteteCommand :: execute\n";
        _receiver->action();
    }

private:
    Receiver* _receiver;
};

class Invoker {
public:
    Invoker(Command* c) : _command(c) {

    }

    //通过调用者调用命令
    void call() {
        cout << "Invoker :: Call\n";
        //通过命令调用接受着的操作函数改变
        _command->execute();
    }
private:
    Command* _command;
};

void commandTest() {
    Receiver* r = new Receiver;
    Command* c = new ConcteteCommand(r);
    Invoker* invoker = new Invoker(c);
    invoker->call();
}

int main(int agrc, const char *agrv[]) {
    commandTest();
    return 0;
}

