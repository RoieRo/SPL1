#include "../include/JoinPolicy.h"
#include "../include/Simulation.h"
#include "../include/SelectionPolicy.h"
#include <iostream>

void LastOfferJoinPolicy::join(Simulation &s, int partyId)
{
    
    int sizeOfVec = s.getParty3(partyId).getOffers().size() - 1;

    int coalId = s.getParty3(partyId).getOffers()[sizeOfVec];
    //Adding the party to the coalition that offered last (the coalition located last in the offer vector)
    s.getCoalitionVec()[coalId].push_back(partyId);
    
    
    // Creating a new Agent clone
    // Note: Agents in the same coalition are clones of the same agent - agents[coalId]
    Agent dupAgent = s.getAgents()[coalId];
    dupAgent.setPartyId(partyId);
    dupAgent.setAgentId(s.getAgents().size());
    s.getAgents2().push_back(dupAgent);
}

// Will be used in Party's Copy Constructor
JoinPolicy *LastOfferJoinPolicy::cloneParty()
{
    JoinPolicy *dup = new LastOfferJoinPolicy();
    return dup;
}