#include "../include/SelectionPolicy.h"
#include "../include/Simulation.h"//Shira added
#include <iostream>

void MandatesSelectionPolicy::select(Simulation &s, std::vector<int> potential, int partyID, int agentId,int mCoalition)
{
    std::cout <<"Just Entered Select of MandatesSelectionPolicy with agentid"<< agentId << std::endl;
    int maxMandats = -1;
    int maxParty = -1;
    int current = -1;
    //Iterating over all the potential parties and checks which one has the most mandates.
    for (unsigned int i = 0; i < potential.size(); i++)
    {
        current = s.getParty(potential[i]).getMandates();
        if (current > maxMandats)
        {
            maxMandats = current;
            maxParty = potential[i];
        }
    }
    if(maxParty > -1)
    {
        //Adding the chosen party's ID to coalitionparties vector
        s.getParty3(maxParty).getOffers().push_back(mCoalition);
        //Setting the chosen party's state.
        s.getParty3(maxParty).setState(State::CollectingOffers) ;
        std::cout <<"chose the party"<< maxParty << std::endl;
    }
}

//Will be used in Agent's Copy Constructor
SelectionPolicy* MandatesSelectionPolicy:: cloneAgent(){
    SelectionPolicy* dup = new MandatesSelectionPolicy();
    return dup;

}