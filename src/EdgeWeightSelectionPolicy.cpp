#include "../include/SelectionPolicy.h"
#include "../include/Simulation.h"//Shira added
void EdgeWeightSelectionPolicy::select(Simulation &s, std::vector<int> potential, int partyID, int agentId)
{
    int maxParty = -1;
    int maxEdge = 0;
    int edge;
    for (int i = 0; i < potential.size(); i++)
    {
        edge = s.getGraph().getEdgeWeight(potential[i], partyID);
        if (edge > maxEdge)
        {
            maxEdge = edge;
            maxParty = i;
        }
    }
    if(maxParty >-1){
        s.getParty(maxParty).getOffers().push_back(agentId);
    }
    
}