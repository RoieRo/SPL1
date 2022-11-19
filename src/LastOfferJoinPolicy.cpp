#include "../include/JoinPolicy.h"//Shira added
#include "../include/Simulation.h"//Shira added
#include "../include/SelectionPolicy.h"//Shira added
#include <iostream>
void LastOfferJoinPolicy::join(Simulation &s, int partyId)
{
    int sizeOfVec= s.getParty3(partyId).getOffers().size()-1;
    int agentId = s.getParty3(partyId).getOffers()[sizeOfVec];
    // I add
    int CoalId = s.getParty3(partyId).getOffers()[sizeOfVec];
    // here i change to  coalId and not agentId
    s.getCoalitionVec()[CoalId].push_back(partyId);
    ///
    std :: cout << " now party number " ;
    std :: cout << partyId;
    std :: cout << " joined to coalition number " ;   
    std :: cout << s.getCoalitionVec()[CoalId][0];
    std :: cout << "    " ; 
    //Creating a new Agent clone
    Agent dupAgent = s.getAgents2()[agentId];
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