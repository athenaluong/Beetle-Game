//
//  Beetle.cpp
//
//

#include "Beetle.h"

namespace cs31
{

    Beetle::Beetle()
    {
        mBody = false;
        mTail = false;
        mLeg1 = false;
        mLeg2 = false;
        mLeg3 = false;
        mLeg4 = false;
        mHead = false;
        mEye1 = false;
        mEye2 = false;
        mAntenna1 = false;
        mAntenna2 = false;
    }

    // convert a tossed die value into a BodyPart
    Beetle::BodyPart Beetle::convertRollToBodyPart(int die) const
    {
        // if not matching, then return NOTVALID
        BodyPart part = BodyPart::NOTVALID;
        if (die == 6)
            part = BodyPart::BODY;
        if (die == 5)
            part = BodyPart::HEAD;
        if (die == 4)
            part = BodyPart::TAIL;
        if (die == 3)
            part = BodyPart::LEG;
        if (die == 2)
            part = BodyPart::ANTENNA;
        if (die == 1)
            part = BodyPart::EYE;
        return(part);
    }

    // build the Beetle's body
    void Beetle::buildBody()
    {
        mBody = true;
    }

    bool Beetle::hasBody() const
    {
        return(mBody);
    }

    // build the Beetle's tail but only if the body has already been built
    void Beetle::buildTail()
    {
        mTail = true;
    }

    bool Beetle::hasTail() const
    {
        return(mTail);
    }

    // build the Beetle's leg but only if the body has already been built
    void Beetle::buildLeg()
    {
        if (!mLeg1) //if doesn't have leg1  
            mLeg1 = true;
        else if (mLeg1 && !mLeg2)
            mLeg2 = true;
        else if (mLeg1 && mLeg2 && !mLeg3)
            mLeg3 = true;
        else if (mLeg1 && mLeg2 && mLeg3 && !mLeg4)
            mLeg4 = true;
    }

    // build Legs 
    bool Beetle::hasLeg1() const
    {
        return(mLeg1);
    }

    bool Beetle::hasLeg2() const
    {
        return(mLeg2);
    }

    bool Beetle::hasLeg3() const
    {
        return(mLeg3);
    }

    bool Beetle::hasLeg4() const
    {
        return(mLeg4);
    }

    // build the Beetle's head but only if the body has already been built
    void Beetle::buildHead()
    {
        mHead = true;
    }

    bool Beetle::hasHead() const
    {
        return(mHead);
    }

    // build the Beetle's eye but only if the head has already been built
    void Beetle::buildEye()
    {
        if (!mEye1) //if doesn't have eye1  
            mEye1 = true;
        else if (mEye1 && !mEye2)
            mEye2 = true;
    }

    bool Beetle::hasEye1() const
    {
        return(mEye1);
    }

    bool Beetle::hasEye2() const
    {
        return(mEye2);
    }

    // build the Beetle's antenna but only if the head has already been built
    void Beetle::buildAntenna()
    {
        if (!mAntenna1) //if doesn't have ey1  
            mAntenna1 = true;
        else if (mAntenna1 && !mAntenna2)
            mAntenna2 = true;
    }

    bool Beetle::hasAntenna1() const
    {
        return(mAntenna1);
    }

    bool Beetle::hasAntenna2() const
    {
        return(mAntenna2);
    }


    bool Beetle::isComplete() const
    {
        return(hasBody() && hasTail() && hasLeg1() && hasLeg2()
            && hasLeg3() && hasLeg4() && hasEye1() && hasEye2() &&
            hasHead() && hasAntenna1() && hasAntenna2());
    }


}
