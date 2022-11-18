#include "Party.h"

#include <iostream>

// Constructor
Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name),
                                                                  mMandates(mandates), mJoinPolicy(jp), mState(Waiting), coolDown(0),offers()
{
    
}

// offers(std::vector <int> (other.offers))
//  Copy Constructor
Party::Party(const Party &other) : mId(other.mId), mName(other.mName), 
mMandates(other.mMandates),mJoinPolicy(other.mJoinPolicy->cloneParty()), mState(other.mState), coolDown(other.coolDown),
offers(other.offers)
{
}

// Copy Assigment Operator
Party &Party::operator=(const Party &other)
{
    if (this != &other)
    {
        if (mJoinPolicy)
        {
            delete mJoinPolicy;
        }
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mJoinPolicy = other.mJoinPolicy->cloneParty();// vector has its own assigment operator
        mState = other.mState;
        coolDown = other.coolDown;
        offers = other.offers;
    }
    return *this;
}

// Destructor
Party::~Party()
{
    if (mJoinPolicy)
    {
        delete mJoinPolicy;
    }
}

// Move
Party::Party(Party &&other) : mId(other.mId), mName(other.mName), 
mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy), mState(other.mState), 
coolDown(other.coolDown),offers(other.offers)
{
    other.mJoinPolicy = nullptr;
}

// Move Assigment Operator
Party &Party ::operator=(Party &&other)
{
    if (this != &other)
    {
        if (mJoinPolicy)
        {
            delete mJoinPolicy;
        }
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mJoinPolicy = other.mJoinPolicy;
        mState = other.mState;
        coolDown = other.coolDown;
        offers = std::move(other.offers); // FISHI
    }
    return *this;
}

//Getters & Setters
State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}
vector<int> Party::getOffers() const
{
    return offers;
}

const string &Party::getName() const
{
    return mName;
}
 //const JoinPolicy Party::getJoin() const
//{
  //  return *mJoinPolicy;
//}

void Party::step(Simulation &s)
{
    if (this->getState() == CollectingOffers)
    {
        this->coolDown++;
        std :: cout << "  the state is  ";
        std :: cout << this->getState() ;

        if (this->coolDown == 3)
        {
            this->mJoinPolicy->join(s, mId);

            mState = Joined;
        }
        std :: cout << "  the cooldown is  ";
        std :: cout << coolDown;
    }
}
 