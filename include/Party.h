#pragma once
#include <string>
#include <vector> //Shira added
#include "JoinPolicy.h" //Shira added

using std::string;
using std::vector;

class JoinPolicy;//INFORMS THE COMPILER THAT CLASS JOINPOLICY EXISTS.
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *);
    // Rule of five
    Party (const Party& other); //Copy Constructor
    Party& operator=(const Party& other);   //Copy Assigment Operator
    virtual ~Party(); //Destructor
    Party(Party&& other);   //Move 
    Party& operator=(Party&& other);    //Move Assigment Operator

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    vector<int> getOffers() const;
    //
    int getId() const;
    // const JoinPolicy getJoin() const;
private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int coolDown;
    vector<int> offers;
};
