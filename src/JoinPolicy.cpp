#include "../include/JoinPolicy.h"
#include "../include/Simulation.h"
JoinPolicy::JoinPolicy(vector<int> moffers) : offers(moffers) {}
void join(Simulation &s, int partyId){};
 vector<int> JoinPolicy::getOffers()  
{
    return offers;
}
