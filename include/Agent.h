#pragma once

#include <vector>
#include "Graph.h"
#include "SelectionPolicy.h" //Shira added

class SelectionPolicy;
class Simulation;   //Shira added

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    // rull of five
    Agent(const Agent& other);
    Agent& operator=(const Agent& other);
    ~Agent();
    // rull of five
    Agent(Agent&& other);
    Agent& operator=( Agent&& other);
    //
    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
/// I made it today
    int getCoalition() const;
     void setCoalition(int coalition);
     //
private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int mCoalition;
};
