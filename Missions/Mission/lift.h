#ifndef LIFT_H
#define LIFT_H
#include"mission.h"

class Lift : public Mission
{
public:
    Lift() : Mission() {}
    void print();
    void help();
    Type getTypeMission();
    void setData(double lift, Sensor sns, Action type);
    void save(std::ofstream& file);
    void load(std::ifstream& file);


    struct inf
    {
        Action type = Action::Other;
        Sensor sns = Sensor::Other;
        double lift = 0;
    };
    inf data;
};

#endif // LIFT_H
