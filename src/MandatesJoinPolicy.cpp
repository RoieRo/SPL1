#include "../include/JoinPolicy.h"//Shira added
#include "../include/Agent.h"//Shira added
#include "../include/Simulation.h"//Shira added
#include "../include/SelectionPolicy.h"//Shira added
void MandatesJoinPolicy::join(Simulation &s, int partyId)
{
    std::cout <<"Just Entered Join of MandatesJoinPolicy with partyid"<< partyId << std::endl;
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
    std::cout << partyId << " Just chose to Join coalition number "<< coalNum << std::endl;
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
