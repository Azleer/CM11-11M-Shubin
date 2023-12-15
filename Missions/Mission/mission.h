#ifndef MISSION_H
#define MISSION_H

#include<iostream>
#include<fstream>


enum class Type   {Dive, Lift, Move, Return, Other};
enum class Action {Stiral, Straight, Other};
enum class Sensor {EchoSounder, Depth, Other};

//Куку.
class Mission {
public:
    Mission() {}
    virtual void print() {std::cout << "Mission ptiny" << std::endl;}
    virtual void help() {}
    virtual Type getTypeMission() {return Type::Other;}
    virtual void save(std::ofstream& file){};
    virtual void load(std::ifstream& file){};
};



#endif // MISSION_H



