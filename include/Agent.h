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

    int getPartyId() const;
    int getId() const;
    void step(Simulation &);

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
};
