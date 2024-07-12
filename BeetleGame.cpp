//
//  BeetleGame.cpp
//

#include "BeetleGame.h"
#include "BeetleDrawing.h"

#include <iostream>

namespace cs31
{

    BeetleGame::BeetleGame() : mHuman(), mComputer(), mHumanDie(), mComputerDie()
    {

    }

    // draw the board by using a BeetleDrawing to draw the two Beetles
    std::string BeetleGame::display(std::string msg) const
    {
        BeetleDrawing drawing(mHuman, mComputer);
        std::string result = drawing.draw() + "\n" + msg;
        return(result);
    }


    // when amount is zero, it is a random roll, otherwise, an amount value is a cheating value
    void BeetleGame::humanRoll(int amount)
    {
        // if the amount is zero, roll the Human's die
        if (amount == 0)
        {
            mHumanDie.roll();
        }

        // otherwise, cheat by forcing the amount into the Human's die
        else
        {
            mHumanDie.setValue(amount);
        }
    }

    // return the value of the Human's die
    int BeetleGame::getHumanDie() const
    {
        return(mHumanDie.getValue());
    }

    // convert the Human's die value to a Beetle's body part
    // then depending on the body part involved, enforce the game ordering of body parts:
    // - namely, body before everything else and head before eyes or antenna
    // if allowed, build the desired body part on the Human's beetle
    // if a body part was successfully built, return true
    // otherwise, return false
    bool BeetleGame::humanPlay()
    {
        bool result = false;
        Beetle::BodyPart part = mHuman.convertRollToBodyPart(getHumanDie());
        switch (part) {
        case Beetle::BodyPart::BODY:
            if (!mHuman.hasBody())
            {
                mHuman.buildBody();
                result = true;
            }
            break;
        case Beetle::BodyPart::TAIL:
            if (mHuman.hasBody() && !mHuman.hasTail())
            {
                mHuman.buildTail();
                result = true;
            }
            break;
        case Beetle::BodyPart::HEAD:
            if (mHuman.hasBody() && !mHuman.hasHead())
            {
                mHuman.buildHead();
                result = true;
            }
            break;
        case Beetle::BodyPart::EYE:
            if (mHuman.hasHead() && (!mHuman.hasEye1() || !mHuman.hasEye2()))
            {
                mHuman.buildEye();
                result = true;
            }
            break;
        case Beetle::BodyPart::ANTENNA:
            if (mHuman.hasHead() && (!mHuman.hasAntenna1() || !mHuman.hasAntenna2()))
            {
                mHuman.buildAntenna();
                result = true;
            }
            break;
        case Beetle::BodyPart::LEG:
            if (mHuman.hasBody() && (!mHuman.hasLeg1() || !mHuman.hasLeg2() || !mHuman.hasLeg3() || !mHuman.hasLeg4()))
            {
                mHuman.buildLeg();
                result = true;
            }
            break;
        case Beetle::BodyPart::NOTVALID:
            break;
        default:
            break;
        }
        return (result);
    }

    // when amount is zero, it is a random roll...
    // otherwise, an amount value is a cheating value...
    void BeetleGame::computerRoll(int amount)
    {
        // if the amount is zero, roll the Computer's die
        if (amount == 0)
        {
            mComputerDie.roll();
        }

        // otherwise, cheat by forcing the amount into the Computer's die
        else
        {
            mComputerDie.setValue(amount);
        }
    }

    //  return the value of the Computer's die
    int BeetleGame::getComputerDie() const
    {
        return(mComputerDie.getValue());
    }

    //  convert the Computer's die value to a Beetle's body part
    // then depending on the body part involved, enforce the game ordering of body parts:
    // - namely, body before everything else and head before eyes or antenna
    // if allowed, build the desired body part on the Computer's beetle
    // if a body part was successfully built, return true
    // otherwise, return false
    bool BeetleGame::computerPlay()
    {
        bool result = false;
        Beetle::BodyPart part = mComputer.convertRollToBodyPart(getComputerDie());
        switch (part) {
        case Beetle::BodyPart::BODY:
            if (!mComputer.hasBody())
            {
                mComputer.buildBody();
                result = true;
            }
            break;
        case Beetle::BodyPart::TAIL:
            if (mComputer.hasBody() && !mComputer.hasTail())
            {
                mComputer.buildTail();
                result = true;
            }
            break;
        case Beetle::BodyPart::HEAD:
            if (mComputer.hasBody() && !mComputer.hasHead())
            {
                mComputer.buildHead();
                result = true;
            }
            break;
        case Beetle::BodyPart::EYE:
            if (mComputer.hasHead() && (!mComputer.hasEye1() || !mComputer.hasEye2()))
            {
                mComputer.buildEye();
                result = true;
            }
            break;
        case Beetle::BodyPart::ANTENNA:
            if (mComputer.hasHead() && (!mComputer.hasAntenna1() || !mComputer.hasAntenna2()))
            {
                mComputer.buildAntenna();
                result = true;
            }
            break;
        case Beetle::BodyPart::LEG:
            if (mComputer.hasBody() && (!mComputer.hasLeg1() || !mComputer.hasLeg2() || !mComputer.hasLeg3() || !mComputer.hasLeg4()))
            {
                mComputer.buildLeg();
                result = true;
            }
            break;
        case Beetle::BodyPart::NOTVALID:
            break;
        default:
            break;
        }
        return (result);
    }

    // check current state of the game
    BeetleGame::GameOutcome  BeetleGame::determineGameOutcome() const
    {
        if (mHuman.isComplete())
            return(GameOutcome::HUMANWONGAME);
        else if (mComputer.isComplete())
            return(GameOutcome::COMPUTERWONGAME);
        else
            return(GameOutcome::GAMENOTOVER);
    }

    std::string  BeetleGame::stringifyGameOutcome() const
    {
        std::string result = "";
        switch (determineGameOutcome())
        {
        case GameOutcome::COMPUTERWONGAME:
            result = "Computer Won!";
            break;
        case GameOutcome::HUMANWONGAME:
            result = "Human Won!";
            break;
        case GameOutcome::GAMENOTOVER:
            result = "Game Not Over!";
            break;
        }
        return(result);
    }

    // check if a player has a completed Beetle
    bool BeetleGame::gameIsOver() const
    {
        return(mHuman.isComplete() || mComputer.isComplete());
    }


    Beetle BeetleGame::getHumanBeetle() const
    {
        return(mHuman);
    }

    Beetle BeetleGame::getComputerBeetle() const
    {
        return(mComputer);
    }

}


