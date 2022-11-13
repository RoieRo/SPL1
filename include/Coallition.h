#pragma once
#include "Simulation.h"
class Coallition
{
public:
    Coallition(int id, int coallMandats);
    ~Coallition();
    int sumOfTotalMandats;  
    void addParty(Party p);
private:
    int cId;    
    int CoallMandats;

};


