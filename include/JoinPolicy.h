#pragma once
#include "Simulation.h"
class Simulation;

class JoinPolicy
{
public:
    //JoinPolicy(vector <int> moffers);
    virtual void join(Simulation &s, int partyId) = 0;
    //const vector <int> getOffers() const ;
};

class MandatesJoinPolicy : public JoinPolicy
{
public:
    //Default constructor
    // MandatesJoinPolicy()=0;
    virtual void join(Simulation &s, int partyId);
};

class LastOfferJoinPolicy : public JoinPolicy
{
public:
    //Default constructor
   // LastOfferJoinPolicy();
    virtual void join(Simulation &s, int partyId);
};