#include "../include/JoinPolicy.h"//Shira added
#include "../include/Agent.h"//Shira added
#include "../include/Simulation.h"//Shira added

void MandatesJoinPolicy::join(Simulation &s, int partyId)
{
    int maxSum = 0;
    int agentId = -1;

    for (int i = 0; i < s.getParty(partyId).getOffers().size(); i++)
    {
        int currSum = 0;
        for (int j = 0; j < s.getCoalitionVec()[i].size(); j++)
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
    Agent dupAgent = s.getAgents2()[agentId];
    s.getAgents2().push_back(dupAgent);
}
