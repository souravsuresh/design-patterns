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
    std::ifstream file_obj("state");
    int state;
    std::vector<int> rem_change;
    std::vector<std::string> lines;
    for(std::string line;getline(file_obj,line);)
    {
        lines.push_back(line);
    }

    //we stored in lines in the vector and then erase all in the file by closing and opening again in trunc mode
    file_obj.close();
    file_obj.open("state",std::ofstream::out|std::ofstream::trunc);
    file_obj.close();

    for(int ind = 0; ind < lines.size(); ++ind)
    {
        int change=0;

        state = std::stoi(std::to_string(lines[ind][0])) - 48;    
        std::cout << lines[ind] << std::endl ;
        rem_change = {};
        for(int i = 2; i<(lines[ind]).size(); i += 2)
        {
           rem_change.push_back(std::stoi(std::to_string(lines[ind][i])) - 48);
        }
        if(state==0 && rem_change[0] == 0)
        {
            std::cout<<"Enter the change and press -1 after finished"<<std::endl;
            std::vector<int> v;
            int inp;
            std::cin>>inp;
            while(inp!=-1)
            {
                v.push_back(inp);
                std::cin >> inp;
            }
            fsm* f = new fsm(v);
            std::cout << "--------------------------------------" << std::endl;
            change = f->get_product();
        }
        else
        {
            fsm* f=new fsm(rem_change,state);
            change=f->get_product();            
        }
        if(change!= -1)
        {

                std::string str="Order is successful and change returned is "+std::to_string(change);
                std::cout<<str<<std::endl;
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
