#pragma once

class JoinPolicy {
//virtual void join()=0;
};
class MandatesJoinPolicy : public JoinPolicy {};

class LastOfferJoinPolicy : public JoinPolicy {};