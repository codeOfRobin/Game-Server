#include "Location.h"
#include "Player.h"
#include "Monopoly.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <iostream>
#include <boost/serialization/string.hpp>
using namespace std;
int main() {
    // create and open a character archive for output
    std::ofstream ofs("filename");

    // create class instance
    Location l1;
    l1.name="soemthig";l1.group=2;
    for (int i = 0; i < 7; ++i)
    {
        l1.cost[i]=i;
        /* code */
    }
    for (int i = 0; i < 6; ++i)
    {
        l1.rent[i]=2*i;
        /* code */
    }
    l1.locationOfObjectFile="ajhsdk/asdc.obj";
    l1.locationNo=5;
    // save data to archive
    {
        boost::archive::text_oarchive oa(ofs);
        // write class instance to archive
        oa << l1;
    	// archive and stream closed when destructors are called
    }
    ofs.close();
    Player p1;
    p1.currentMoney=300;
    p1.currentPosition=422;
    std::ofstream ofs2("filename2");
        // save data to archive
    {
        boost::archive::text_oarchive oa(ofs2);
        // write class instance to archive
        oa << p1;
        // archive and stream closed when destructors are called
    }

    ofs2.close();

    Monopoly game;
    game.locations.push_back(l1);
    game.players.push_back(p1);
    game.currency="dollar";
    std::ofstream ofs3("filename3");
    {
        boost::archive::text_oarchive oa(ofs3);
        // write class instance to archive
        oa << game;
        // archive and stream closed when destructors are called
    }
    ofs3.close();
    Monopoly game2;
    std::ifstream ifs("filename3");
        boost::archive::text_iarchive ia(ifs);
        // read class state from archive
        ia >> game2;
        cout<<game2.locations[0].rent[1]<<endl;
        cout<<game2.players[0].currentPosition<<"how cool is this?";
        // archive and stream closed when destructors are called

    return 0;
}