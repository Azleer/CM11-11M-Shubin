#ifndef MOVE_H
#define MOVE_H
#include"mission.h"

class Move : public Mission
{
public:
    Move() : Mission() {}
    void print();
    void help();
    Type getTypeMission();
    void setData(double x, double y, Action type, Sensor sns, double accuracy);
    void save(std::ofstream& file);
    void load(std::ifstream& file);


    struct inf
    {
        Action type = Action::Other;
        Sensor sns = Sensor::Other;
        double x = 0, y = 0;
        double accuracy = 0;
    };
    inf data;
};

#endif // MOVE_H
