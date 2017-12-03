#include <iostream>
class state{
    public:
        state(){}
        virtual bool is_final();
        virtual void handle();
        virtual ~state()=default;
};
class context
{
    public:
        state* s;
    public:
        context(state* st):s(st){}
        void request_handle();
        bool check_final();
        void set_state(state&);


};

class state0: public state
{
    public:
        bool is_final();
        void handle();
};

class state1: public state
{
    public:
        bool is_final();
        void handle();
};

class state2: public state
{
    public:
        bool is_final();
        void handle();
};

class state3: public state
{
    public:
        bool is_final();
        void handle();
};
class state4: public state
{
    public:
        bool is_final();
        void handle();
};

class state5: public state
{
    public:
        bool is_final();
        void handle();

};


