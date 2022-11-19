#include "../include/JoinPolicy.h"//Shira added
#include "../include/Simulation.h"//Shira added
#include "../include/SelectionPolicy.h"//Shira added
#include <iostream>
void LastOfferJoinPolicy::join(Simulation &s, int partyId)
{
    std::cout <<"Just Entered Join of LastOfferJoinPolicy with partyid"<< partyId << std::endl;
    int sizeOfVec= s.getParty3(partyId).getOffers().size()-1;
    
    int coalId = s.getParty3(partyId).getOffers()[sizeOfVec];
    
    s.getCoalitionVec()[coalId].push_back(partyId);
    std::cout << partyId << " Just chose to Join coalition number "<< coalId << std::endl;
    //Creating a new Agent clone 
    //Note: Agents in the same coalition are clones of the same agent - agents[coalId]
    
    Agent dupAgent = s.getAgents()[coalId];
    dupAgent.setPartyId(partyId);
    dupAgent.setAgentId(s.getAgents().size());
    s.getAgents2().push_back(dupAgent); 
}

//Will be used in Party's Copy Constructor
JoinPolicy* LastOfferJoinPolicy::cloneParty()
{
    JoinPolicy* dup = new LastOfferJoinPolicy();
    return dup;
}