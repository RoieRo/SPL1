#include "../include/SelectionPolicy.h"
void MandatesSelectionPolicy ::select(Simulation &s, vector<int> potential, int partyID, int agentId)
{
    int maxParty = -1;
    int maxEdge = 0;
    int edge;
    for (int i = 0; i < potential.size(); i++)
    {
        edge = s.getParty(potential[i]).getMandates();
        if (edge > maxEdge)
        {
            maxEdge = edge;
            maxParty = i;
        }
    }
}
