#ifndef DIVE_H
#define DIVE_H
#include "mission.h"

enum class Diving {Spiral, Diving1, Diving2,};

class Dive : Mission
{
public:
    Dive();
    double get_depthSensor();
    double get_depth();
    int get_typeDiving();
    void set_depthSensor();
    void set_depth();
    void set_typeDiving();


private:
        double depthSensor;
        double depth;
        Diving Type = Diving::Spiral;
};

#endif // DIVE_H
