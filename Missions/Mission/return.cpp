#include "return.h"
#include <iostream>

void Return::print()
{
    std::cout << "Return"  << std::endl;
}

void Return::help()
{
    std::cout << "Return \t\t\t\t\t - Returning the ROV back to the starting point."  << std::endl;
}

Type Return::getTypeMission()
{
    return Type::Return;
}

void Return::save(std::ofstream& file)
{
    file << "Return"  << std::endl;
}

void Return::load(std::ifstream& file)
{

}


