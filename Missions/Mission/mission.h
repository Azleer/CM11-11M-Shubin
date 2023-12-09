#ifndef MISSION_H
#define MISSION_H

#include<iostream>

enum class Type   {Dive, Lift, Move, Return};
enum class Action {Stiral, Straight};
enum class Sensor {EchoSounder, Depth};
//Куку.
class Mission {
public:
    Type mission;
    struct data
    {
       Action type;
       Sensor sns;
       double depth;
       double x, y, z;
       double accuracy;
    };
    void info();

};

#endif // MISSION_H



