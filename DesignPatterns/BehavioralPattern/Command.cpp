/*
 * Created by weyiua on 2021/8/9.
 * ����ģʽ
 * ͨ����ͬ������ʹ֮��ͬ�Ĳ���
 *
 * ��ɫ
 * Command: ����������
 * ConcreteCommand: ����������
 * Invoker: ������
 * Receiver: ������
 * Client:�ͻ���
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

    //ͨ�������ߵ�������
    void call() {
        cout << "Invoker :: Call\n";
        //ͨ��������ý����ŵĲ��������ı�
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

