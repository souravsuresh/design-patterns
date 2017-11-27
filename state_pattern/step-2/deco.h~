#ifndef DECO_H
#define DECO_H
#include <iostream>
//#include "state.h"
class Component
{
        public:
                bool is_decorated=false;
                virtual void call();
           
};

class Decorator: public Component
{
        private:
                Component* cp;
        public:
                //Context* context;
                Decorator(Component* c):cp(c){}
                virtual void call();
                friend class CompDeco1;
                friend class CompDeco2;
};

class CompDeco1: public Decorator
{

        public:
                CompDeco1(Component* cp):Decorator(cp){}
                void call();
};
class CompDeco2: public Decorator
{

        public:
                CompDeco2(Component* cp):Decorator(cp){}
                void call();
};

#endif
