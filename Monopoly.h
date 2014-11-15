//
//  Monopoly.h
//  
//
//  Created by Robin Malhotra on 24/10/14.
//
//

#ifndef ____Monopoly__
#define ____Monopoly__

#include <iostream>
#include <string>
#include <vector>
#include <boost/serialization/vector.hpp>
#include "Location.h"
#include "Player.h"
const int MAX_NO_OF_CITIES=50;
using namespace std;

class Monopoly
{
public:
    string currency;
    float startingMoney;
    float jailFine;
    float taxPercent;
    bool graph[MAX_NO_OF_CITIES][MAX_NO_OF_CITIES];
    vector <Location> locations;
    vector <Player> players;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
    	ar & currency;
    	ar & startingMoney;
    	ar & jailFine;
    	ar & taxPercent;
    	ar &graph;
    	ar & locations;
    	ar & players;
    }

    
};
#endif /* defined(____Monopoly__) */
