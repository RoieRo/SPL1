#pragma once

//#include "../include/Simulation.h" //Shira added
class Simulation;

class JoinPolicy
{
public:
    //const vector <int> getOffers() const ;
    virtual void join(Simulation &s, int partyId) = 0;
    virtual JoinPolicy* cloneParty() = 0;
    virtual ~JoinPolicy()=default;
};

class MandatesJoinPolicy : public JoinPolicy
{
public:
    virtual ~MandatesJoinPolicy() = default;
    virtual void join(Simulation &s, int partyId) override;
    virtual JoinPolicy* cloneParty() override;
};

class LastOfferJoinPolicy : public JoinPolicy
{
public:
    //Default constructor
   // LastOfferJoinPolicy();
    virtual ~LastOfferJoinPolicy() = default;
    virtual void join(Simulation &s, int partyId) override;
    virtual JoinPolicy* cloneParty() override;
};