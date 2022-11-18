#include "../include/SelectionPolicy.h"
#include "../include/Simulation.h" //Shira added
void EdgeWeightSelectionPolicy::select(Simulation &s, std::vector<int> potential, int partyID, int agentId,int mCoalition)
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
            maxParty = potential[i];
        }
    }

    if (maxParty > -1)
    {
        s.getParty(maxParty).getOffers().push_back(mCoalition);
        // all this is only for test
        std ::cout << " here its ok ";
        std ::cout << " here its ok ";
        std ::cout << " num mandats of party that chosed ";
        std ::cout << s.getParty(maxParty).getMandates();
        std ::cout << " insert to offer vector ";
        std ::cout << agentId;
        std ::cout << " next itertion ";
        std ::cout << "    ";
        for (auto element : s.getParty(maxParty).getOffers())
        {
            std ::cout << " LOOpppppp ";
            std ::cout << element;
        }
         std ::cout << " the party state at first is : " ; 
         std ::cout <<s.getParty3(maxParty).getState() ;
         //this is not a part from the test
         s.getParty3(maxParty).setState(CollectingOffers);
         // here test continue
         std ::cout << " the party state sec  is : " ; 
         std ::cout <<s.getParty3(maxParty).getState() ;
         std ::cout << "  " ; 
    }
}

//Will be used in Agent's Copy Constructor
SelectionPolicy* EdgeWeightSelectionPolicy::cloneAgent(){
    SelectionPolicy* dup = new EdgeWeightSelectionPolicy();
    return dup;
}