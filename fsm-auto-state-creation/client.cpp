#include "fsm.cpp"
#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <sstream>
#include <string>

int main()
{
    
    std::ifstream file_obj_t;
    std::ifstream file_obj("state");
    int state;
    std::vector<int> rem_change;
    std::vector<std::string> lines;
    for(std::string line;getline(file_obj,line);)
    {
        lines.push_back(line);
    }
    file_obj.close();
    file_obj.open("state",std::ofstream::out|std::ofstream::trunc);
    file_obj.close();

    for(int ind = 0; ind < lines.size(); ++ind)
    {
        int change=0;

        state = std::stoi(std::to_string(lines[ind][0])) - 48;    
        std::cout << lines[ind] << std::endl ;
        std::string s="";
        for(int i = 2; i<(lines[ind]).size(); i += 1)
        {
            if(lines[ind][i]==' ')
            {
                rem_change.push_back(std::stoi(s));
                s="";
            }
            else
                s+=lines[ind][i];
            
        
        }
        rem_change.push_back(std::stoi(s));
        if(state==0 && rem_change[0] == 0)
        {
            file_obj_t.open("products");
            std::vector<std::string> lines;
            for(std::string line;getline(file_obj_t,line);)
            {
                lines.push_back(line);
            }
            std::cout<<"sl. No."<<"\t\t"<<"Item Name"<<"\t\t"<<"Price(Inr)"<<std::endl;
            int temp=1;
            for(auto i=lines.begin();i!=lines.end();i+=2)
            {
                std::cout<<temp++<<"\t\t"<<*i<<"\t\t"<<*(i+1)<<std::endl;
            }
            std::cout<<"Enter the Item Number: ";
            int product_no;
            std::cin>>product_no;
            std::cout<<std::endl;
            std::vector<int> dim;
            std::cout<<"What all denominations you have?"<<std::endl;
            std::string s="";
            std::string inp_string;
            int it=0;
            while(std::getline(std::cin,inp_string)&& it<1){it++;}
            for(int ii=0;ii<inp_string.size();++ii)
            {
                if(inp_string[ii]==' ')
                {
                    
                 	dim.push_back(std::stoi(s));
                 	s="";
                }
                else
                {
                    s+=inp_string[ii];
                }
            }
            dim.push_back(std::stoi(s));
            std::vector<int> v;
            int inp;
            
            for(auto i=dim.begin();i!=dim.end();++i)
            {
                std::cout<<"Enter number of "<<*i<<" ruppee coins: ";
           
                std::cin>>inp;
                for(int j=0;j<inp;++j)
                    v.push_back(*i);
            }
            fsm* f=new fsm(v,stoi(lines[((product_no-1)*2)+1]));
            change = f->get_product();
        }
        else
        {
            int final_s=*(rem_change.end()-1);
            
            rem_change.pop_back();
            fsm* f=new fsm(rem_change,final_s,state);
            change=f->get_product();    
        }
        if(change!= -1)
        {

                std::string str="Order is successful and change returned is "+std::to_string(change);
                std::cout<<str<<std::endl;
                break;
        }
        else
        {
                std::cout<<"Problem with your order please enter correct change"<<std::endl;
                std::ofstream file_obj;
                file_obj.open("state");
                std::string s="0 0";
                file_obj.write(s.c_str(),4);
                file_obj.close();
        }
    }   
}
