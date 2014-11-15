//
//  Player.h
//  
//
//  Created by Robin Malhotra on 25/10/14.
//
//

#ifndef ____Player__
#define ____Player__

#include <fstream>
#include <boost/archive/text_oarchive.hpp>

class Player
{
public:
    float currentMoney;
    int currentPosition;
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
    	ar & currentPosition;
    	ar & currentMoney;
    }
};
#endif /* defined(____Player__) */
