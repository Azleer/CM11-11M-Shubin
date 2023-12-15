#include "lift.h"


void Lift::print()
{
    std::cout << "Lift to " << data.lift

              << " m use sensor " << (int)data.sns
              << " Type of movment " << (int)data.type <<   std::endl;
}

void Lift::help()
{
    std::cout << "Lift [depth] [sns] [type] \t\t - Lift to [depth], use sensor [sns]. Type of movment [type]. \n"
              << "\t\t\t\t\t - depth: [0,-100] m; \n"
              << "\t\t\t\t\t - types: 0 - Stiral, 1 - Straight, 2 - Oher;\n"
              << "\t\t\t\t\t - sensor: 0 - EchoSounder, 1 - Depth, 2 - Other;\n" << std::endl;
}

Type Lift::getTypeMission()
{
    return Type::Lift;
}

void Lift::setData(double lift, Sensor sns, Action type)
{
    if ((lift >= 0 && lift <= 100))
    {
        data.lift = lift;
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

void Lift::save(std::ofstream& file)
{
    file << "Lift to " << data.lift
         << " m use sensor " << (int)data.sns
         << " Type of movment " << (int)data.type <<   std::endl;
}

void Lift::load(std::ifstream& file)
{

}

