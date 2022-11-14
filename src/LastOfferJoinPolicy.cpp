#include "../include/JoinPolicy.h"
void LastOfferJoinPolicy::join(Simulation &s, int partyId)
{
int agentId=offers[offers.size()-1];
s.getCoalitionVec()[agentId].push_back(partyId);
    Agent dupAgent= s.getAgents2()[agentId];
    s.getAgents2().push_back(dupAgent);
}