#include "deco.h"
int main()
{
        //Component *c=new Component();
        Component *c;
        c=new Component();
        c->call();
        c=new CompDeco1(c);
        c->call();
        //c=new CompDeco1(c);
        c->call();        
}
