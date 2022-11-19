#include "Agent.h"
#include "Simulation.h"
#include <iostream>
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId),
 mPartyId(partyId), mSelectionPolicy(selectionPolicy), mCoalition(-1)
{
    // You can change the implementation of the constructor, but not the signature!
}

// Copy Constructor 
// Be aware that you need to change it's mAgentId field according to agents vector!
// AKA mPartyId field.
Agent::Agent(const Agent &other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId),
                                   mSelectionPolicy(other.mSelectionPolicy->cloneAgent()),
                                   mCoalition(other.mCoalition)
{
    std::cout <<"Agent Copy Constructor"<< std::endl;
}   

Agent::~Agent() // Destructor
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

// //  Move constructor
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
    vector<int> potentialParties;
    for (int currParty = 0; currParty < sim.getGraph().getNumVertices(); currParty++)
    {
        if(sim.getParty(currParty).getState() != Joined)
        {
            if(sim.getGraph().getEdgeWeight(currParty, mPartyId)> 0)
            {
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
    mSelectionPolicy->select(sim, potentialParties, mPartyId, mAgentId, mCoalition);
}
//     std::cout <<"Just Entered Agent step with agentid"<< mAgentId << std::endl;
//     vector<int> potentialParties;
    
//     bool isOk = true;

//     for (int i = 0; i < sim.getGraph().getNumVertices(); i++) // Iterating over all the parties
//     {
        
//         // Checks if a party is a neighboor and its state
        
//         if (mPartyId != i && isOk && (sim.getGraph().getEdgeWeight(mPartyId, i)>0) && sim.getGraph().getParty(i).getState() != State::Joined)
//         {
           
//             for (unsigned int j = 0; j < sim.getParty3(i).getOffers().size(); j++)
//             {
//                 if (mCoalition == sim.getParty3(i).getOffers()[j])
//                     isOk = false;
//             }
            
//             if (isOk)
//             {
//                 potentialParties.push_back(i);
//             }
//             else
//             {
//                 isOk = true;
//             }
//         }
//     }
    
//     mSelectionPolicy->select(sim, potentialParties, mPartyId, mAgentId, mCoalition);
// }
