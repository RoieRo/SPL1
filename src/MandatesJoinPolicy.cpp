#include "../include/JoinPolicy.h"
#include "../include/Agent.h"
#include "../include/Simulation.h"
#include "../include/SelectionPolicy.h"

void MandatesJoinPolicy::join(Simulation &s, int partyId)
{
    int maxSum = 0;
    int coalNum = -1;

    //Iterating over the coalitions that offerd this party to join their coalition.
    for (unsigned int i = 0; i < s.getParty3(partyId).getOffers().size(); i++)
    {
        int currSum = 0;
        int offeredCoal = s.getParty3(partyId).getOffers()[i];
        for (unsigned int j = 0; j < s.getCoalitionVec()[offeredCoal].size(); j++)
        {
            //Suming offeredCoal mandates
            currSum = currSum + s.getParty(s.getCoalitionVec()[offeredCoal][j]).getMandates();
        }
        if (currSum > maxSum)
        {
            maxSum = currSum;
            coalNum = offeredCoal;
        }
    }
    
    //Adding party to coalitionparties vector.
    s.getCoalitionVec()[coalNum].push_back(partyId);
    
    //Creating a new Agent clone
    Agent dupAgent = s.getAgents()[coalNum];
    dupAgent.setPartyId(partyId);
    dupAgent.setAgentId(s.getAgents().size());
    s.getAgents2().push_back(dupAgent);
}

//Will be used in Party's Copy Constructor
JoinPolicy* MandatesJoinPolicy::cloneParty()
{
    JoinPolicy* dup = new MandatesJoinPolicy();
    return dup;
}
