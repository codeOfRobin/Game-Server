//
//  Location.h
//  
//
//  Created by Robin Malhotra on 24/10/14.
//
//

#ifndef ____Location__
#define ____Location__

#include <fstream>
#include <boost/archive/text_oarchive.hpp>

class Location {
    
    
public:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
    	ar & cost;
    	ar & rent;
    	ar & locationOfObjectFile;
    	ar & group;
    	ar &locationNo;
    	ar & name;
    }
    float cost[7];
    float rent[6];
    std::string locationOfObjectFile;
    int group;
    int locationNo;
    std::string name;
    
};

#endif /* defined(____Location__) */
