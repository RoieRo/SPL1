#include "../include/SelectionPolicy.h"
#include "../include/Simulation.h"//Shira added
#include "iostream"

void MandatesSelectionPolicy ::select(Simulation &s, std::vector<int> potential, int partyID, int agentId,int mCoalition)
{
    int maxMandats = -1;
    int maxParty = -1;
    int current;
    //ASK ROIE <
    for (int i = 0; i <= potential.size(); i++)
    {
        current = s.getParty(potential[i]).getMandates();
        if (current > maxMandats)
        {
            maxMandats = current;
            maxParty = i;
        }
    }
    if(maxParty >-1){
        s.getParty(maxParty).getOffers().push_back(mCoalition);
        // from here test
        std :: cout << " here its ok " ;
        std :: cout << " num of party that chosed " ;
        std :: cout <<  s.getParty(maxParty).getMandates() ;
        std :: cout << "    " ;
        for (auto element : s.getParty(maxParty).getOffers())
         {
            
            std :: cout << " LOOpppppp " ;
            std :: cout << element ;
         }
        // finish test
        // to update the state of party
         s.getParty3(maxParty).setState(CollectingOffers) ;
        
    }
}

//Will be used in Agent's Copy Constructor
SelectionPolicy* MandatesSelectionPolicy:: cloneAgent(){
    SelectionPolicy* dup = new MandatesSelectionPolicy();
    return dup;

}