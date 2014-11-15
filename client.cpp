#include "Location.h"
#include "Player.h"
#include "Monopoly.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <iostream>
#include <boost/serialization/string.hpp>
using namespace std;
int
main()
{
    for(int i=0 ;i<=1;i++)
    {
    Message msg;

    msg._a="hio"+ to_string(i);
    msg._b="I rock";
    boost::asio::streambuf buf;
    std::ostream os( &buf );
    boost::archive::text_oarchive ar( os );
    ar & msg;

    boost::asio::io_service io_service;
    boost::asio::ip::tcp::socket socket( io_service );
    short port = i+1234;
    socket.connect(
            boost::asio::ip::tcp::endpoint(
                boost::asio::ip::address::from_string( "10.0.0.4" ),
                port
                )
            );

    const size_t header = buf.size();
    std::cout << "buffer size " << header << " bytes" << std::endl;

    // send header and buffer using scatter
    std::vector<boost::asio::const_buffer> buffers;
    buffers.push_back( boost::asio::buffer(&header, sizeof(header)) );
    buffers.push_back( buf.data() );
    const size_t rc = boost::asio::write(
            socket,
            buffers
            );
    std::cout << "wrote " << rc << " bytes" << std::endl;;
    socket.close();
}}