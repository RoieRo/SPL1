#include "Agent.h"
#include "Simulation.h"
#include "iostream"
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), mCoalition(0)
{
    // You can change the implementation of the constructor, but not the signature!
}
// // Copy Constructor
Agent::Agent(const Agent &other) :
 mAgentId(other.mAgentId), mPartyId(mPartyId), 
 mSelectionPolicy(other.mSelectionPolicy),
 mCoalition(other.mCoalition)
{
}
// destructor
Agent::~Agent() {
    
}
// Copy assignment operator
Agent& Agent::operator=(const Agent& other)
{
    if(this != &other)
    {
        
    }

}
// //  Move constructor
Agent::Agent(Agent&& other) :
mAgentId(other.mAgentId), mPartyId(mPartyId),
mSelectionPolicy(other.mSelectionPolicy),
mCoalition(other.mCoalition)

{}

// // move assignment operator
Agent& Agent:: operator=(Agent&& other) {
    if (this!= &other)
    {
        delete this;
        mAgentId=other.mAgentId;
        mPartyId=other.mPartyId;
        mSelectionPolicy=other.mSelectionPolicy;
        mCoalition=other.mCoalition;
         //other.mAgentId= ;
         //other.mPartyId=nullptr;
        other.mSelectionPolicy=nullptr;
    }
    
 }
/// get coalition I made today
int Agent::getCoalition() const
{
    return mCoalition;
}
/// I made today
void Agent::setCoalition(int coalition)
{
    mCoalition = coalition;
}
int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::step(Simulation &sim)
{

    vector<int> potentialParties;
    int num = sim.getGraph().getNumVertices() - 1;
    bool isOk = true;

    for (int i = 0; i < num; i++)//iterating over all the parties
    {
        std :: cout << " loop step 1 " ;
        //checks if a party is a neighboor and its state
        if (mPartyId != i && isOk && sim.getGraph().getEdgeWeight(mPartyId, i) > 0 && sim.getGraph().getParty(i).getState() != Joined)
        {
            std :: cout << " loop step 2 " ;
            //checks if our coalition allready offered party i to join.
            for (int j = 0; j < sim.getParty(i).getOffers().size(); j++)
            {
                std :: cout << " loop step 3 " ;
                if (mAgentId == sim.getParty(i).getOffers()[j])
                    isOk = false;
                    std :: cout << " loop step 4 " ;
            }
            // isOk=true;
            // insert third condition.
            // then insert i into potentialpARTIES.
            if (isOk)
            {
                potentialParties.push_back(i);
                std :: cout << " loop step 5 " ;
            }
        }
    }
    mCoalition = this->getCoalition();
    this->mSelectionPolicy->select(sim,potentialParties,mPartyId,mAgentId,mCoalition);
}
