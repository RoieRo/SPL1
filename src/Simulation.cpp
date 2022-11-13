#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents)
{
}

void Simulation::step()
{
    // TODOoo: implement this method
    for (int i = 0; i < mGraph.getNumVertices(); i++)
    {
        
        mGraph.getParty2(i).step(*this);
    }

    for (int i = 0; i < mAgents.size(); i++)
    {
        mAgents[i].step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    const vector<vector<int>> coalitionParties = this->getPartiesByCoalitions();
    for (int i = 0; i < coalitionParties.size(); i++)
    {
        int sumMandates = 0;
        for (int j = 0; j < coalitionParties[i].size(); j++)
        {
            sumMandates = +mGraph.getMandates(coalitionParties[i][j]);
        }
        if (sumMandates >= 61)
        {
            return true;
        }
    }
    for (int i = 0; i < mGraph.getNumVertices(); i++)
    {
        if (mGraph.getParty(i).getState() != Joined)
        {
            return false;
        }
    }
    return true;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    return vector<vector<int>>();
}
