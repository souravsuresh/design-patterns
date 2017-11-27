#ifndef DECO_H
#define DECO_H
#include <iostream>

class Component
{
        public:
                virtual void call();
           
};

class Decorator: public Component
{
        private:
                Component* cp;
        public:
                Decorator(Component* c):cp(c){}
                virtual void call();
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
