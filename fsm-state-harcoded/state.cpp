#include "state.h"
#include <fstream>

std::ofstream file_obj;

bool state0::is_final()
{
    return false;
}

bool state4::is_final()
{
    return false;
}
bool state3::is_final()
{
    return false;
}
bool state2::is_final()
{
    return false;
}
bool state1::is_final()
{
    return false;
}
bool state::is_final()
{
    return false;
}
bool state5::is_final()
{
    return 1;
}


bool context::check_final()
{
    return s->is_final();
}
void context::request_handle()
{
    s->handle();
}
void context::set_state(state& s)
{
    *(this->s)=s;
}
void state::handle()
{
}
void state0::handle()
{
    file_obj.open("state");
    file_obj.write((char*)"0 ",1);
    file_obj.close();
}
void state1::handle()
{
    file_obj.open("state");
    file_obj.write((char*)"1",1);
    file_obj.close();
}
void state2::handle()
{
    file_obj.open("state");
    file_obj.write((char*)"2",1);
    file_obj.close();
}
void state3::handle()
{
    file_obj.open("state");
    file_obj.write((char*)"3",1);
    file_obj.close();
}
void state4::handle()
{
    file_obj.open("state");
    file_obj.write((char*)"4",1);
    file_obj.close();
}
void state5::handle()
{
    file_obj.open("state");
    file_obj.write((char*)"5",1);
    file_obj.close();
}


