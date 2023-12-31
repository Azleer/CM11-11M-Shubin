#ifndef DIVE_H
#define DIVE_H
#include"mission.h"
class Dive :  public Mission
{
public:
    Dive() : Mission() {}
    void print();
    void help();
    Type getTypeMission();
    void setData(double dive, Sensor sns, Action type);
    void save(std::ofstream& file);
    void load(std::ifstream& file);

    struct inf
    {
        Action type = Action::Other;
        Sensor sns = Sensor::Other;
        double dive = 0;
    };
    inf data;

};

#endif // DIVE_H
