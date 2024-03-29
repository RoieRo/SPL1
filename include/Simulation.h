#pragma once

#include <vector>
#include <iostream>//Shira added

//#include "Graph.h"
#include "Agent.h"

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    Party &getParty3(int partyId) ;
    const vector<vector<int>> getPartiesByCoalitions() const;
    vector<vector<int>> &getCoalitionVec();
    vector<Agent> &getAgents2();
    

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<vector<int>> coalitionVec;
};
