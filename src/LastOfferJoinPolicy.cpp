#include "../include/JoinPolicy.h"
//#include "../include/Simulation.h"

void LastOfferJoinPolicy::join(Simulation &s, int partyId)
{
    int sizeOfVec= s.getParty(partyId).getOffers().size()-1;
    int agentId = s.getParty(partyId).getOffers()[sizeOfVec];


    s.getCoalitionVec()[agentId].push_back(partyId);

    Agent dupAgent = s.getAgents2()[agentId];

    s.getAgents2().push_back(dupAgent);
}