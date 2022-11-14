#include "Agent.h"
#include "Simulation.h"
#include "JoinPolicy.h"
#include "Party.h"
#include "Graph.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    // You can change the implementation of the constructor, but not the signature!
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::step(Simulation &sim)
{
    
    // TODO: implement this method
    vector<int> potentialParties;
    int num = sim.getGraph().getNumVertices()-1;
    for (int i = 0; i < num; i++)
    {
        if(sim.getGraph().getEdgeWeight(mPartyId, i)>0 && sim.getGraph().getParty(i).getState() != Joined ){
            for(int j=0; j< sim.getGraph().getParty(i)->mJoinPolicy.getOffers().size();j++)
            {
               
            }
            
            //insert third condition.
                //then insert i into potentialpARTIES.
              potentialParties.push_back(i);  
        }

    }
    
    //this->mSelectionPolicy->select(&sim);
}
