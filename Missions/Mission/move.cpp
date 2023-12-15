#include "move.h"


void Move::print()
{
    std::cout << "Move to point " << data.x << " , " << data.y
              << "m with precision "<< data.accuracy
              << "m use sensor " << (int)data.sns
              << " Type of movment " << (int)data.type <<   std::endl;
}

void Move::help()
{
    std::cout << "Move [x] [y] [type] [sns] [accuracy] \t - Move to point [x],[y] with precision [accuracy], use sensor [sns]. Type of movment [type]. \n"
              << "\t\t\t\t\t - x,y: [0,10000] m; \n"
              << "\t\t\t\t\t - types: 0 - Stiral, 1 - Straight, 2 - Oher;\n"
              << "\t\t\t\t\t - sensor: 0 - EchoSounder, 1 - Depth, 2 - Other;\n"
              << "\t\t\t\t\t - accurancy: [0-100] m.\n" << std::endl;
}

Type Move::getTypeMission()
{
    return Type::Move;
}

void Move::setData(double x, double y, Action type, Sensor sns, double accuracy)
{
    if ((x >= 0 && x <=10000 ))
    {
        data.x = x;
    } else {
        std::cout << "Coordinate x - out of range." << std::endl;
    }
    if ((y >= 0 && y <=10000 ))
    {
        data.y = y;
    } else {
        std::cout << "Coordinate y - out of range." << std::endl;
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
    if (accuracy >= 0 && accuracy <= 100) {
        data.accuracy = accuracy;
    } else {
        std::cout << "Accuracy - out of range" << std::endl;
    }
}

void Move::save(std::ofstream& file)
{
    file << "Move to point " << data.x << " , " << data.y
         << " m with precision "<< data.accuracy
         << " m use sensor " << (int)data.sns
         << " Type of movment " << (int)data.type <<   std::endl;
}

void Move::load(std::ifstream& file)
{

}

