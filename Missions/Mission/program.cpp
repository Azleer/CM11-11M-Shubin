#include "program.h"



void Program::run()
{
    while(!this->exit)
    {
        this->tick();
        this->screenRefresh();
    }
}

void Program::screenRefresh()
{

}

void Program::tick()
{

}
