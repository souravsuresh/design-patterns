#include "state.h"
#include <vector>
#include <algorithm>
class fsm{
    int curr_change;
    int current_state;
    context* c;
    public:
        fsm():c(new context(new state0())),current_state(0){}
        state* do_transaction();
        void set_change(int change);
        int get_product(std::vector<int>);
};
void fsm::set_change(int ch)
{
    curr_change=ch;
}
//transition logic
state* fsm::do_transaction()
{
    switch(current_state)
    {
        case 0:
            switch(curr_change)
            {
                case 1:
                    //write to file
                    current_state=1;
                    return new state1();
                case 2:
                    current_state=2;
                    return new state2();
                case 5:
                    current_state=5;
                    std::cout<<"========================"<<std::endl;
                    return new state5();
                default:
                    current_state=-1;
                    return new state();
            }
        case 1:
            switch(curr_change)
            {
                case 1:
                    //write to file
                    current_state=2;
                    return new state2();
                case 2:
                    current_state=3;
                    return new state3();
                default:
                    current_state=-1;
                    return new state();
            }
        case 2:
            switch(curr_change)
            {
                case 1:
                    //write to file
                    current_state=3;
                    return new state3();
                case 2:
                    current_state=4;
                    return new state4();
                default:
                    current_state=-1;
                    return new state();
            } 
        case 3:
            switch(curr_change)
            {
                case 1:
                    //write to file
                    current_state=4;
                    return new state4();
                case 2:
                    current_state=5;
                    return new state5();
                default:
                    current_state=-1;
                    return new state();
            }           
        case 4:
            switch(curr_change)
            {
                case 1:
                    //write to file
                    current_state=5;
                    return new state5();
                default:
                    current_state=-1;
                    return new state();
            }  
        case 5:
            switch(curr_change)
            {
                default:
                    current_state=-1;
                    return new state();
            }

    }

}
// void set_context(context* c)
// {
//     this.c=c;
// }
int fsm::get_product(std::vector<int> change)
{
    sort(change.begin(),change.end());
    int ret=-1;
    for_each(change.begin(),change.end(),[this,&ret](auto ch){
        //std::cout<<"--"<<ch<<std::endl;
        this->set_change(ch);
        c->s=this->do_transaction();
        //std::cout<<s->is_final();
        //std::cout<<"===>"<<curr_change<<"<=="<<current_state<<"-->"<<c->check_final()<< std::endl;
        if(current_state!=-1)
            std::cout<<"\n";
        //    c->set_state(*s);
        else
        {
            if(curr_change==2)
                ret=1;
        }
        if(c->check_final())
        {
            //std::cout<<"hekko";    
            ret=0;
        }
    });
    return ret;
}
