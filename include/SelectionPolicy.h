#pragma once
#include "Simulation.h"
#include "Agent.h"

class SelectionPolicy { 
    public:
    virtual void select(Simulation &s,vector<int> potential,int partyID, int agentId) = 0;
};
class MandatesSelectionPolicy: public SelectionPolicy{
    public:
    virtual void select(Simulation &s,vector<int> potential,int partyID, int agentId);
 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{ 
    public:
    virtual void select(Simulation &s,vector<int> potential,int partyID, int agentId);
};