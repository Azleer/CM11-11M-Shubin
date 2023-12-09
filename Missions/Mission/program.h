#ifndef PROGRAM_H
#define PROGRAM_H

#include<list>
#include"mission.h"
#include"dive.h"

class Program
{
public:
    Program();
    void run();
private:
    void screenRefresh();
    void tick();

    bool exit = 1;
    std::list<Mission> tasks;
};

#endif // PROGRAM_H
