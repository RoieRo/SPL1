#include "../include/JoinPolicy.h"//Shira added
#include "../include/Simulation.h"//Shira added
#include <iostream>
void LastOfferJoinPolicy::join(Simulation &s, int partyId)
{
    int sizeOfVec= s.getParty(partyId).getOffers().size()-1;
    int agentId = s.getParty(partyId).getOffers()[sizeOfVec];
    // I add
    int CoalId = s.getParty(partyId).getOffers()[sizeOfVec];
    // here i change to  coalId and not agentId
    s.getCoalitionVec()[CoalId].push_back(partyId);
    ///
    std :: cout << " now party number " ;
    std :: cout << partyId;
    std :: cout << " joined to " ;   
    std :: cout << s.getCoalitionVec()[CoalId][0];
    //
    Agent dupAgent = s.getAgents2()[agentId];
    
    s.getAgents2().push_back(dupAgent);

}