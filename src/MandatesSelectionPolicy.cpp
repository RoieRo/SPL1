#include "../include/SelectionPolicy.h"
#include "../include/Simulation.h"//Shira added
#include "iostream"

void MandatesSelectionPolicy ::select(Simulation &s, std::vector<int> potential, int partyID, int agentId)
{
    int maxMandats = -1;
    int maxParty = -1;
    int current;
    for (int i = 0; i <= potential.size(); i++)
    {
        std :: cout << " LOOpppppp 1!! " ;
        current = s.getParty(potential[i]).getMandates();
        if (current > maxMandats)
        {
            maxMandats = current;
            maxParty = i;
        }
    }
    if(maxParty >-1){
        s.getParty(maxParty).getOffers().push_back(agentId);
        std :: cout << " here its ok " ;
        std :: cout << " num of party that chosed " ;
        std :: cout <<  s.getParty(maxParty).getMandates() ;
         std :: cout << "    " ;
        for (auto element : s.getParty(maxParty).getOffers())
         {
            std :: cout << " LOOpppppp " ;
            std :: cout << element ;
         }

         s.getParty3(maxParty).setState(CollectingOffers) ;
        
    }
}
