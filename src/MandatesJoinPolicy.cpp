#include "../include/JoinPolicy.h"//Shira added
#include "../include/Agent.h"//Shira added
#include "../include/Simulation.h"//Shira added
#include "../include/SelectionPolicy.h"//Shira added
void MandatesJoinPolicy::join(Simulation &s, int partyId)
{
    int maxSum = 0;
    int agentId = -1;

    for (unsigned int i = 0; i < s.getParty3(partyId).getOffers().size(); i++)
    {
        int currSum = 0;
        for (unsigned int j = 0; j < s.getCoalitionVec()[i].size(); j++)
        {
            currSum = currSum + s.getParty(s.getCoalitionVec()[i][j]).getMandates();
        }
        if (currSum > maxSum)
        {
            maxSum = currSum;
            agentId = i;
        }
    }
    s.getCoalitionVec()[agentId].push_back(partyId);
    //Creating a new Agent clone
    Agent dupAgent = s.getAgents2()[agentId];
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
