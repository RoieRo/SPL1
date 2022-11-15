#include "Party.h"
#include <vector>
#include "JoinPolicy.h"

 using std :: vector;
//constructor
Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), coolDown(0)
{
    vector<int> offers;
    // You cannn change the implementation of the constructor, but not the signature!
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
    // TODO: implement this method

    if (this->getState() == CollectingOffers)
    {

        if (this->coolDown == 3)
        {
            this->mJoinPolicy->join(s, mId);

            mState = Joined;
        }
        this->coolDown++;
    }
}
