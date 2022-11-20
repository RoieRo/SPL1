#include "Agent.h"
#include "Simulation.h"
#include <iostream>

// Constructor
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId),
 mPartyId(partyId), mSelectionPolicy(selectionPolicy), mCoalition(-1)
{
    
}

// Copy Constructor 
// For duplicating mSelectionPolicy we used cloneAgent method.
Agent::Agent(const Agent &other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId),
                                   mSelectionPolicy(other.mSelectionPolicy->cloneAgent()),
                                   mCoalition(other.mCoalition)
{
    std::cout <<"Agent Copy Constructor"<< std::endl;
}

// Destructor
Agent::~Agent() 
{
    if (mSelectionPolicy)
    {
        delete mSelectionPolicy;
    }
}
// Copy assignment operator
Agent& Agent::operator=(const Agent &other)
{
    if (this != &other)
    {
        if(mSelectionPolicy)
            delete mSelectionPolicy;
        mAgentId = other.mAgentId;  
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy->cloneAgent();
        mCoalition = other.mCoalition;
    }
    return *this;
}

// Move constructor
Agent::Agent(Agent &&other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId),
                              mSelectionPolicy(other.mSelectionPolicy),
                              mCoalition(other.mCoalition)
{
  other.mSelectionPolicy = nullptr;
  
}
 
// Move assignment operator
Agent& Agent::operator=(Agent&& other)
{
    if (this != &other)
    {
        if(mSelectionPolicy){
            delete mSelectionPolicy;  
        }
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy;
        mCoalition = other.mCoalition;
        other.mSelectionPolicy = nullptr;
    }
    return *this;
}

// Getters & Setters

int Agent::getCoalition() const
{
    return mCoalition;
}

void Agent::setCoalition(int coalition)
{
    mCoalition = coalition;
}
int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::setPartyId(int newPartyID) 
{
    mPartyId = newPartyID;
}

void Agent::setAgentId(int newAgentID)
{
    mAgentId = newAgentID;
}

void Agent::step(Simulation &sim)
{
    std::cout <<"Just Entered Agent step with agentid"<< mAgentId << std::endl;
    vector<int> potentialParties; //Party ID's that follow the 3 conditions will be inserted to potentialParties vector.
    
    //Iterating over all the parties in the Graph.
    for (int currParty = 0; currParty < sim.getGraph().getNumVertices(); currParty++)
    {
        //checks if the current party is in state Waiting or CollectingOffers.
        if(sim.getParty(currParty).getState() != Joined)
        {
            //Checks if the current party is a neighboor of the agents's party.
            if(sim.getGraph().getEdgeWeight(currParty, mPartyId)> 0)
            {
                //Checks if the agent's coalition already offered the current party to join.
                bool flag = true;
                for(unsigned int j=0; j< sim.getParty3(currParty).getOffers().size(); j++)
                {
                    if(mCoalition == sim.getParty3(currParty).getOffers()[j])
                    {
                        flag = false;
                    }
                }
                if(flag){
                    potentialParties.push_back(currParty);
                }
            }
        }
    }
    //The agent will choose a party from the potential parties vector by its selection policy.
    mSelectionPolicy->select(sim, potentialParties, mPartyId, mAgentId, mCoalition);
};
