#include "../include/SelectionPolicy.h"
#include "../include/Simulation.h"//Shira added
#include <iostream>

void MandatesSelectionPolicy::select(Simulation &s, std::vector<int> potential, int partyID, int agentId,int mCoalition)
{
    std::cout <<"Just Entered Select of MandatesSelectionPolicy with agentid"<< agentId << std::endl;
    int maxMandats = -1;
    int maxParty = -1;
    int current = -1;
    for (unsigned int i = 0; i < potential.size(); i++)
    {
        current = s.getParty(potential[i]).getMandates();
        if (current > maxMandats)
        {
            maxMandats = current;
            maxParty = potential[i];
        }
    }
    if(maxParty > -1){
        s.getParty3(maxParty).getOffers().push_back(mCoalition);
        // // from here test
        // std :: cout << " here its ok " ;
        // std :: cout << " num of party that chosed " ;
        // std :: cout <<  s.getParty(maxParty).getMandates() ;
        // std :: cout << "    " ;
        // vector<int> vecOffers = s.getParty3(maxParty).getOffers();
        // for (auto element : vecOffers)
        //  {
            
        //     std :: cout << " LOOpppppp " ;
        //     std :: cout << element ;
        //  }
        // // finish test
        // // update the state of party
        s.getParty3(maxParty).setState(State::CollectingOffers) ;
        std::cout <<"chose the party"<< maxParty << std::endl;
    }
}

//Will be used in Agent's Copy Constructor
SelectionPolicy* MandatesSelectionPolicy:: cloneAgent(){
    SelectionPolicy* dup = new MandatesSelectionPolicy();
    return dup;

}