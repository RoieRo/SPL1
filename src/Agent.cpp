#include "Agent.h"
#include "Simulation.h"
#include "iostream"
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

    vector<int> potentialParties;
    int num = sim.getGraph().getNumVertices() - 1;
    bool isOk = true;

    for (int i = 0; i < num; i++)//iterating over all the parties
    {
        std :: cout << " loop step 1 " ;
        //checks if a party is a neighboor and its state
        if (mPartyId != i && isOk && sim.getGraph().getEdgeWeight(mPartyId, i) > 0 && sim.getGraph().getParty(i).getState() != Joined)
        {
            std :: cout << " loop step 2 " ;
            //checks if our coalition allready offered party i to join.
            for (int j = 0; j < sim.getParty(i).getOffers().size(); j++)
            {
                std :: cout << " loop step 3 " ;
                if (mAgentId == sim.getParty(i).getOffers()[j])
                    isOk = false;
                    std :: cout << " loop step 4 " ;
            }
            // isOk=true;
            // insert third condition.
            // then insert i into potentialpARTIES.
            if (isOk)
            {
                potentialParties.push_back(i);
                std :: cout << " loop step 5 " ;
            }
        }
    }
    this->mSelectionPolicy->select(sim,potentialParties,mPartyId,mAgentId);
}
