/*
 * Created by weyiua on 2021/8/9.
 * �н���ģʽ
 *
 * ��ɫ
 * Mediator: �����н���
 * ConcreteMediator: �����н���
 * Colleague: ����ͬ����
 * ConcreteColleague: ����ͬ����
 */

class Colleague;

class Mediator {
public:
    virtual void operation(int) {

    }

    void register(Colleague* c) {
        this->_cplleague = c;
    }
protected:
    Colleague* _colleague;
};

class Colleague {
public:
    virtual void sendmsg(int) {

    }

    virtual void setMediator(Mediator* m) {
    }
};

class ConcreteMediator : public Mediator {
public:
    void operation(int) {
        _colleague.s
    }
};



class ConcreteColleagueA : public Colleague {
public:
    void setMediator(Mediator* m) {
        this->_mediator = m;
    }
private:
    Mediator* _mediator;
};

class ConcreteColleagueB : public Colleague {
public:
    void setMediator(Mediator* m) {
        this->_mediator = m;
    }
private:
    Mediator* _mediator;
};

