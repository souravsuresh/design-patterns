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
        if(!cp->is_decorated)
        {
                std::cout<<"Decorating in 1st decorator"<<std::endl;
                cp->is_decorated=true;
        }
        else
                cp->is_decorated=false;
        Decorator::call();
        
}

void CompDeco2::call()
{
        if(!cp->is_decorated)
        {
                std::cout<<"Decorating in 2nd decorator"<<std::endl;
                cp->is_decorated=true;
        }
        else
                cp->is_decorated=false;
        Decorator::call();
        
}
