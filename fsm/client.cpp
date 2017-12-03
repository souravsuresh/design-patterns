#include "fsm.cpp"
#include <iostream>
#include <vector>
int main()
{
    std::cout<<"Enter the change and press -1 after finished"<<std::endl;
    std::vector<int> v;
    int inp;
    std::cin>>inp;
    while(inp!=-1)
    {
        v.push_back(inp);
        std::cin>>inp;
    }
    fsm* f=new fsm();
    int change=f->get_product(v);
    std::cout<<change<<std::endl;
    if(change!= -1)
        std::cout<<"Order is successful and change returned is "<<change<<std::endl;
    else
        std::cout<<"Problem with your order please enter correct change"<<std::endl;
}