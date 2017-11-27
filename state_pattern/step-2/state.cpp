#include "state.h"

void Context::request()
{
        s->handle();
}

void Decorated::handle()
{
        //std::cout<<"already decorated erasing"<<std::endl;
        Decorator::call();
}

void ToBeDecorated::handle()
{
        std::cout<<"Decorating"<<std::endl;
        Decorator::call();
}

