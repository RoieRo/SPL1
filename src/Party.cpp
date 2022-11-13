#include "Party.h"
#include <vector>
Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), coolDown(0)
{
    // You cannn change the implementation of the constructor, but not the signature!
}

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

const string & Party::getName() const
{
    return mName;
}
///
int Party::getId() const
{
    return mId;
}  
///
void Party::step(Simulation &s)  
{
    // TODO: implement this method
    
    if(this->getState()==CollectingOffers)  {
    
        if(this->coolDown==3)   {
          //this->mJoinPolicy->join(s, *this);

        }  
        this->coolDown++;
    }
    
}
