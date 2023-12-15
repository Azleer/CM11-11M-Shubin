#include "dive.h"

void Dive::print()
{
    std::cout << "Dive to " << data.dive

              << " m use sensor " << (int)data.sns
              << " Type of movment " << (int)data.type <<   std::endl;
}

void Dive::help()
{
    std::cout << "Dive [depth] [sns] [type] \t\t - Dive to [depth], use sensor [sns]. Type of movment [type]. \n"
              << "\t\t\t\t\t - depth: [0,-100] m; \n"
              << "\t\t\t\t\t - types: 0 - Stiral, 1 - Straight, 2 - Oher;\n"
              << "\t\t\t\t\t - sensor: 0 - EchoSounder, 1 - Depth, 2 - Other;\n" << std::endl;
}

Type Dive::getTypeMission()
{
    return Type::Dive;
}

void Dive::setData(double dive, Sensor sns, Action type)
{
    if ((dive >= 0 && dive <=100 ))
    {
        data.dive = dive;
    } else {
        std::cout << "lift - out of range." << std::endl;
    }
    if ((int)type >= 0 && (int)type <= 2) {
        data.type = type;
    } else {
        std::cout << "No such type." << std::endl;
    }
    if ((int)sns >= 0 && (int)sns <= 2) {
        data.sns = sns;
    } else {
        std::cout << "No such sns." << std::endl;
    }
}

void Dive::save(std::ofstream& file)
{
    file << "Dive to " << data.dive
         << " m use sensor " << (int)data.sns
         << " Type of movment " << (int)data.type <<   std::endl;
}

void Dive::load(std::ifstream& file)
{

}


