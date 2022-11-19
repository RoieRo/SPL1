#include "../include/SelectionPolicy.h"
#include "../include/Simulation.h" //Shira added
#include <vector>

void EdgeWeightSelectionPolicy::select(Simulation &s, std::vector<int> potential, int partyID, int agentId,int mCoalition)
{
    int maxParty = -1;
    int maxEdge = 0;
    int edge;
    
    for (unsigned int i = 0; i < potential.size(); i++)
    {
        edge = s.getGraph().getEdgeWeight(potential[i], partyID);
        if (edge > maxEdge)
        {
            maxEdge = edge;
            maxParty = potential[i];
        }
    }

    if (maxParty > -1)
    {
        s.getParty3(maxParty).getOffers().push_back(mCoalition);
         //this is not a part from the test
         s.getParty3(maxParty).setState(CollectingOffers);
    }
}

//Will be used in Agent's Copy Constructor
SelectionPolicy* EdgeWeightSelectionPolicy::cloneAgent(){
    SelectionPolicy* dup = new EdgeWeightSelectionPolicy();
    return dup;
}