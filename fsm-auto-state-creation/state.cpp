#include "state.h"
#include <fstream>

std::ifstream file_obj_t;
using namespace std;
bool state::is_final()
{
    return false;
}

ConcreteState::ConcreteState(int final_state)
{
	state_no=0;
	file_obj_t.open("products");
	this->final_state=final_state;

}
bool ConcreteState::is_final()
{
	return final_state<=get_state();
}
void ConcreteState::handle(){
	std::ofstream file_obj;
	file_obj.open("state");
  file_obj.write(to_string(get_state()).c_str(),to_string(get_state()).size());
  file_obj.close();
}
void ConcreteState::set_state(int n)
{
	state_no=n;
}
int ConcreteState::get_state()
{
	return state_no;
}
bool context::check_final()
{
    return s->is_final();
}

void context::request_handle()
{
    this->s->handle();
}
void context::set_state(int s)
{
    this->s->set_state(s);
}
int context::get_state()
{
	return this->s->get_state();
}
void state::handle()
{
	cout<<"here"<<endl;
}

//  int main()
//  {
//  		context* c=new context(new ConcreteState());
//  		c->set_state(11);
//  		cout<<c->check_final()<<"\n";
// 		c->request_handle();
//  }

