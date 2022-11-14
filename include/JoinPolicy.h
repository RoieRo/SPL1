#pragma once
#include "Simulation.h"

class JoinPolicy
{
public:
    JoinPolicy(vector<int> moffers);
    virtual void join(Simulation &s, int partyId) = 0;
    vector<int> getOffers()  ;

protected:
    vector<int> offers;
};
class MandatesJoinPolicy : public JoinPolicy
{
public:
    virtual void join(Simulation &s, int partyId);

private:
    vector<int> offers;
};

class LastOfferJoinPolicy : public JoinPolicy
{
public:
    virtual void join(Simulation &s, int partyId);

private:
    vector<int> offers;
};