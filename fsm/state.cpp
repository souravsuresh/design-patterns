#include "state.h"
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
    std::cout<<"here\n";
    return false;
}
bool state5::is_final()
{
    //std::cout<<"here in 5\n";
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
    std::cout<<"endl";
}
void state0::handle()
{
    std::cout<<"endl";
}
void state1::handle()
{
    std::cout<<"endl";
}
void state2::handle()
{
    std::cout<<"endl";
}
void state3::handle()
{
    std::cout<<"endl";
}
void state4::handle()
{
    std::cout<<"endl";
}
void state5::handle()
{
    std::cout<<"endl";
}


