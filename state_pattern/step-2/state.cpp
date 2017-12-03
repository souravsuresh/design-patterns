#include "state.h"
//#include "deco.h"
bool Context::is_decorated()
{
        if(s->is_decorated)
                return true;
        else
                return false;

}
void Context::request()
{
        s->handle();
}

void Decorated::handle()
{
        //std::cout<<"already decorated erasing"<<std::endl;
        //ecorator::call();
}

void ToBeDecorated::handle()
{
        std::cout<<"Decorating"<<std::endl;
        //Decorator::call();
}

