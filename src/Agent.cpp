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

    vector<int> potentialParties;
    int num = sim.getGraph().getNumVertices() - 1;
    bool isOk = true;

    for (int i = 0; i < num; i++)//iterating over all the parties
    {
        //checks if a party is a neighboor and its state
        if (sim.getGraph().getEdgeWeight(mPartyId, i) > 0 && sim.getGraph().getParty(i).getState() != Joined)
        {
            //checks if our coalition allready offered party i to join.
            for (int j = 0; j < sim.getParty(i).getOffers().size()&& isOk; j++)
            {
                if (mAgentId == sim.getParty(i).getOffers()[j])
                    isOk = false;
            }
            // isOk=true;
            // insert third condition.
            // then insert i into potentialpARTIES.
            if (isOk)
            {
                potentialParties.push_back(i);
            }
        }
    }
    //this->mSelectionPolicy->select(sim,potentialParties,mPartyId,mAgentId);
}
