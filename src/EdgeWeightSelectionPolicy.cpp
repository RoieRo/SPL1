#include "../include/SelectionPolicy.h"
#include "../include/Simulation.h" //Shira added
#include <vector>

void EdgeWeightSelectionPolicy::select(Simulation &s, std::vector<int> potential, int partyID, int agentId,int mCoalition)
{
    std::cout <<"Just Entered Select of EdgeWeightSelectionPolicy with agentid:  "<< agentId << std::endl;
    std::cout <<"This Agent is from Coalition number: "<< mCoalition << std::endl;
    int maxParty = -1;
    int maxEdge = 0;
    int edge;
    
    for (unsigned int i = 0; i < potential.size(); i++)
    {
        std::cout <<"agent checked party number"<< potential[i] << std::endl;
        edge = s.getGraph().getEdgeWeight(potential[i], partyID);
        if (edge > maxEdge)
        {
            maxEdge = edge;
            maxParty = potential[i];
        }
    }

    if (maxParty > -1)
    {
        std::cout <<"agent chose  party number"<< maxParty << std::endl;
        s.getParty3(maxParty).getOffers().push_back(mCoalition);
        s.getParty3(maxParty).setState(State::CollectingOffers);
    }
}

//Will be used in Agent's Copy Constructor
SelectionPolicy* EdgeWeightSelectionPolicy::cloneAgent(){
    SelectionPolicy* dup = new EdgeWeightSelectionPolicy();
    return dup;
}