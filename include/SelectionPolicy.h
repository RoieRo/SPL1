#pragma once
#include <vector>
//#include "../include/Simulation.h"

class Simulation;//Shira added

class SelectionPolicy { 
    public:
    virtual void select(Simulation &s,std::vector<int> potential,int partyID, int agentId) = 0;
};
class MandatesSelectionPolicy: public SelectionPolicy{
    public:
    virtual void select(Simulation &s,std::vector<int> potential,int partyID, int agentId)override;
 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{ 
    public:
    virtual void select(Simulation &s,std::vector<int> potential,int partyID, int agentId) override;
};