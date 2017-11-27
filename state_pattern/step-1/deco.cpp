#include "deco.h"
void Decorator::call()
{
        std::cout<<"Abstract decorator\n";
        cp->call();
}

void Component::call()
{
        std::cout<<"Abstract Component\n";
}

void CompDeco1::call()
{
        std::cout<<"Decorator 1"<<std::endl;
        Decorator::call();
}

void CompDeco2::call()
{
        std::cout<<"Decorator 2"<<std::endl;
        Decorator::call();
}
