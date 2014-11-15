#ifndef MESSAGE_H
#define MESSAGE_H

#include <boost/serialization/string.hpp>

#include <string>

struct Message
{
    std::string _a;
    std::string _b;
    
    template <class Archive>
    void serialize(
                   Archive& ar,
                   unsigned int version
                   )
    {
        ar & _a;
        ar & _b;
    }
};

#endif