#include "../include/SelectionPolicy.h"
#include "../include/Simulation.h"//Shira added

void MandatesSelectionPolicy ::select(Simulation &s, std::vector<int> potential, int partyID, int agentId)
{
    int maxMandats = -1;
    int maxParty = -1;
    int current;
    for (int i = 0; i < potential.size(); i++)
    {
        current = s.getParty(potential[i]).getMandates();
        if (current > maxMandats)
        {
            maxMandats = current;
            maxParty = i;
        }
    }
    if(maxParty >-1){
        s.getParty(maxParty).getOffers().push_back(agentId);
    }
}
