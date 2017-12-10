#include "state.h"
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <functional>
#include <signal.h>
#include <stdlib.h>
#include <fstream>

using namespace std;
vector<int> temp;
void myfunction(int sig)
{

    std::ofstream file_obj;
    file_obj.open("state",std::ofstream::app);
    for_each(temp.begin(),temp.end(),[&file_obj](auto c){
        
        file_obj.write((char*)(" "),1);
        file_obj.write(std::to_string(c).c_str(),1);
        //file_obj.close();
    });
    file_obj.write("\n",2);
    file_obj.close();

    exit(0);
    
}
class fsm{
    int curr_change;
    int current_state;
    context* c;
    public:
        vector<int> change;
        fsm(vector<int> ch,int state=0):current_state(state){
            switch(state)
            {
                case 0:
                    c=(new context(new state0()));
                    break;
                case 1:
                    c=(new context(new state1()));
                    break;
                case 2:
                    c=(new context(new state2()));
                    break;
                case 3:
                    c=(new context(new state3()));
                    break;
                case 4:
                    c=(new context(new state4()));
                    break;
                case 5:
                    c=(new context(new state5()));
                    break;
            }
            for_each(ch.begin(),ch.end(),[this,&temp](auto c){
                this->change.push_back(c);
                temp.push_back(c);
            });

        }
        state* do_transaction();
        void set_change(int change);
        int get_product();
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
                    current_state=1;
                    return new state1();
                case 2:
                    current_state=2;
                    return new state2();
                case 5:
                    current_state=5;
                    return new state5();
                default:
                    current_state=-1;
                    return new state();
            }
        case 1:
            switch(curr_change)
            {
                case 1:
                    
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
int fsm::get_product()
{
    signal(SIGINT,myfunction);
    int ret=-1;
    find_if(this->change.begin(),this->change.end(),[this,&ret,&temp](auto ch){
        cout<<"Currrent Change: "<<ch<<std::endl;
        this->set_change(ch);
        cout<<"\t\tcurr_state"<<endl;
        cout<<"BEFORE: ";
        cout<<"\t"<<current_state<<endl;
        c->s=this->do_transaction();
        cout<<"AFTER: ";
        cout<<"\t\t"<<current_state<<endl;
        
        c->request_handle();
        temp.erase(temp.begin());
        usleep(2000000);
        if(current_state==-1)
        {
            if(curr_change==2)
                ret=1;
           
        }
        if(c->check_final())
        {
            ret=0;
            for_each(temp.begin(),temp.end(),[&ret](auto r){
                ret+=r;
                //std::cout<<"=-=-=here-->  "<<ret<<std::endl;
            });
            std::ofstream file_obj;
            file_obj.open("state");
            std::string s="0 0";
            file_obj.write(s.c_str(),3);
            file_obj.close();
            
            
            return ret;
            
        }
        else
            return 0;
        cout<<"----------------------------\n";
    });
    if(ret==0 || ret==1)
    {
        cout<<"Item is dispensed"<<endl;
        std::ofstream file_obj;
        file_obj.open("state");
        std::string s="0 0";
        file_obj.write(s.c_str(),3);
        file_obj.close();
    }
    return ret;
}
