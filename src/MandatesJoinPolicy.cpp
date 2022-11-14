#include "../include/JoinPolicy.h"

void MandatesJoinPolicy::join(Simulation &s, int partyId)
{
    int maxSum = 0;
    int agentId = -1;

    for (int i = 0; i < offers.size(); i++)
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
