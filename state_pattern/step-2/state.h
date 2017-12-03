#ifndef STATE
#define STATE 
#include <iostream>
class State
{
        public:
                State(){}
                int is_decorated;
                virtual void handle()=0;
                virtual ~State()=default;
};
class Context
{
        private:
                State* s;


        public:
                Context(State* st):s(st){}
                void request();
                bool is_decorated();

};
class Decorated:public State
{
        public:
                Decorated(){is_decorated=1;}
                void handle();
};
class ToBeDecorated:public State
{
        public:
                ToBeDecorated(){is_decorated=0;}
                void handle();
};
#endif