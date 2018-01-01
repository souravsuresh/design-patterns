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
int final_s=0;
void myfunction(int sig)
{

    std::ofstream file_obj;
    file_obj.open("state",std::ofstream::app);
    for_each(temp.begin(),temp.end(),[&file_obj](auto c){
        
        file_obj.write((char*)(" "),1);
        file_obj.write(std::to_string(c).c_str(),1);
        
    });
    file_obj.write((char*)(" "),1);
    file_obj.write(to_string(final_s).c_str(),to_string(final_s).size());
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
        fsm(vector<int> ch,int final_state,int state=0):current_state(state){
            final_s=final_state;
            c=new context(new ConcreteState(final_state));
            c->set_state(state);
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
    c->set_state(c->get_state()+curr_change);
    current_state=c->get_state();
}

int fsm::get_product()
{
    int fin=0;
    signal(SIGINT,myfunction);
    int ret=-1;
    find_if(this->change.begin(),this->change.end(),[this,&fin,&ret,&temp](auto ch){
        cout<<"Currrent Change: "<<ch<<std::endl;
        this->set_change(ch);
        cout<<"\t\tcurr_state"<<endl;
        cout<<"BEFORE: ";
        cout<<"\t"<<current_state<<endl;
        this->do_transaction();
        
        cout<<"AFTER: ";
        if(c->check_final())
            cout<<"\t\t"<<final_s<<endl;
        else
            cout<<"\t\t"<<current_state<<endl;
        c->request_handle();
        temp.erase(temp.begin());
        usleep(2000000);
        if(c->check_final())
        {
            ret=0;
            for_each(temp.begin(),temp.end(),[&ret,&fin](auto r){
                ret+=r;
            });
            if(temp.size()==0)
                ret=c->get_state()-final_s;
            std::ofstream file_obj;
            file_obj.open("state");
            std::string s="0 0";
            file_obj.write(s.c_str(),3);
            file_obj.close();            
            cout<<ret<<endl;
            fin=-1;
            return ret;          
        }

        else
            return 0;
        
    });
    cout<<"----------------------------\n";

    if(c->check_final() && fin!=-1)
    {
        
        cout<<"Item is dispensed"<<endl;
        std::ofstream file_obj;
        file_obj.open("state");
        std::string s="0 0";
        file_obj.write(s.c_str(),3);
        file_obj.close();
        cout<<"=---"<<c->get_state()<<":"<<final_s<<"\n";
        
        ret=c->get_state()-final_s;
    }
    return ret;
}
