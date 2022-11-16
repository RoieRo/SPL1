#pragma once

#include <vector>

//#include "Graph.h"
#include "Agent.h"
#include "JoinPolicy.h"

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
    const vector<vector<int>> getPartiesByCoalitions() const;
    vector<vector<int>> getCoalitionVec();
    vector<Agent> &getAgents2();
    

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<vector<int>> coalitionVec;
};
