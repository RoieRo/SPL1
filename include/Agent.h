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
    // Rule of five
    Agent(const Agent& other);  // Copy Constructor
    Agent& operator=(const Agent& other);   // Copy Assigment Operator
    virtual ~Agent();   //Destructor
    Agent(Agent&& other);   //Move
    Agent& operator=( Agent&& other);   //Move Assigment Operator
    //
    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
/// I made it today
    int getCoalition() const;
    void setCoalition(int coalition);
    void setPartyId(int newPartyID); //SHIRA
    void setAgentId(int newAgentID); //SHIRA
    
private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int mCoalition;
};
