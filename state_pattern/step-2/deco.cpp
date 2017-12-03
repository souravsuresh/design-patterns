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
        if(!context->is_decorated())
        {
                std::cout<<"Decorating in 1st decorator"<<std::endl;
                //cp->is_decorated=true;
                context=new Context(new Decorated());
        }
        else
                //cp->is_decorated=false;
                context=new Context(new ToBeDecorated());
        Decorator::call();
        
}

void CompDeco2::call()
{
        if(!context->is_decorated())
        {
                std::cout<<"Decorating in 2nd decorator"<<std::endl;
                context=new Context(new Decorated());
                //cp->is_decorated=true;
        }
        else
                context=new Context(new ToBeDecorated());
        Decorator::call();
        
}