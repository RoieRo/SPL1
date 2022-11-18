#pragma once
#include <vector>
//#include "../include/Simulation.h"

class Simulation;//Shira added

class SelectionPolicy { 
    public:
    virtual ~SelectionPolicy() = default;
    virtual void select(Simulation &s,std::vector<int> potential,int partyID, int agentId, int mCoalition) = 0;
    virtual SelectionPolicy* cloneAgent() = 0;
};
class MandatesSelectionPolicy: public SelectionPolicy{
    
    public:
     virtual ~MandatesSelectionPolicy() = default;
     void select(Simulation &s,std::vector<int> potential,int partyID, int agentId, int mCoalition) override;
     SelectionPolicy* cloneAgent() override;
 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{ 
    public:
     virtual ~EdgeWeightSelectionPolicy() = default;
     void select(Simulation &s,std::vector<int> potential,int partyID, int agentId,int mCoalition) override;
     SelectionPolicy* cloneAgent() override;
};