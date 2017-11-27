#include <iostream>

class Context
{
        private:
                State* s;
        public:
                Context(State* st):s(st){}
                void request();
};

class State
{
        public:
                virtual void handle();
};
class Decorated:public State
{
        public:
                void handle();
};
class ToBeDecorated:public State
{
        public:
                void handle();
};
