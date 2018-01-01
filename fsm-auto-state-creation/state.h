#include <iostream>
#include <vector>
#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <set>
#include <sstream>
#include <string>
class state{
    private:
        int final_state;
    public:
		std::set<int> product;
        state(){}
        virtual bool is_final();
        virtual void handle();
        virtual ~state()=default;
        virtual void set_state(int n)=0;
        virtual int get_state()=0;
};

class context
{
    public:
        state* s;
    public:
        context(state* st):s(st){}
        void request_handle();
        bool check_final();
    		void set_state(int);
				int get_state();

};

class ConcreteState: public state
{
	private:
		int state_no;
		std::set<int> product;
        int final_state;
	public:
		ConcreteState(int final_state);
		bool is_final();
    void handle();
    void set_state(int n);
    int get_state();
};
