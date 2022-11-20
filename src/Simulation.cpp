#include "Simulation.h"
#include <iostream>
using namespace std ;

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), coalitionVec()
{
    //When a simulation is intilized, each agent in mAgents represents a new coalition.
    coalitionVec.resize(mAgents.size());
    for (unsigned int k = 0; k < mAgents.size(); k++)
    {
        coalitionVec[k].push_back(mAgents[k].getPartyId());
        mAgents[k].setCoalition(k);
    }
}

void Simulation::step()
{
    std::cout << "Just Entered Simulation step" << std::endl;
    //Iterating over all the parties.
    for (int i = 0; i < mGraph.getNumVertices(); i++)
    {
        std::cout << "Entering Party step for Party " << i << std::endl;
        
        mGraph.getParty2(i).step(*this);
    }
    //Iterating over all the agents.
    for (unsigned int i = 0; i < mAgents.size(); i++)
    {
        mAgents[i].step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    const vector<vector<int>> coalitionParties = getPartiesByCoalitions();
    //Checks if there is a coalition that has more than 61 mandats.
    for (unsigned int i = 0; i < coalitionParties.size(); i++)
    {
        int sumMandates = 0;

        std::cout << "Suming coalition number " << i << std::endl;

        for (unsigned int j = 0; j < coalitionParties[i].size(); j++)
        {
            std::cout << "party number " << coalitionParties[i][j] << std::endl;
            sumMandates = sumMandates + mGraph.getMandates(coalitionParties[i][j]);
        }
        if (sumMandates >= 61)
        {
            std::cout << "Terminated because we have coalition with " << sumMandates << " mandates" << std::endl;
            return true;
        }
    }
    //Checks if one of the parties hasn't joined a coalition yet.
    for (int i = 0; i < mGraph.getNumVertices(); i++)
    {
        if (mGraph.getParty(i).getState() != State::Joined)
        {
            return false;
        }
    }
    std::cout <<"Terminated because all the parties Joined a coalition"<< std::endl;
    
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
 vector<Agent> &Simulation::getAgents2() 
{
    return mAgents;
}
const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}
 Party &Simulation::getParty3(int partyId) 
{
    return mGraph.getParty2(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    return coalitionVec;  
}

vector<vector<int>> & Simulation::getCoalitionVec()
{
    return coalitionVec;
}
