#ifndef RETURN_H
#define RETURN_H
#include"mission.h"

class Return : public Mission
{
public:
    Return() : Mission() {};
    void print();
    void help();
    Type getTypeMission();
    void save(std::ofstream& file);
    void load(std::ifstream& file);
};

#endif // RETURN_H
