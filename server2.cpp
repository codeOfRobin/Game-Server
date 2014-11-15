#include "Message.h"

#include <boost/archive/text_iarchive.hpp>

#include <boost/asio.hpp>

int
main()
{
    while(true)
    {
    boost::asio::io_service io_service;
    const uint16_t port = 1235;
    boost::asio::ip::tcp::acceptor acceptor(
            io_service,
            boost::asio::ip::tcp::endpoint(
                boost::asio::ip::address::from_string( "10.0.0.4" ),
                port
                )
            );
   
        /* code */
    
    boost::asio::ip::tcp::socket socket( io_service );
    acceptor.accept( socket );
    std::cout << "connection from " << socket.remote_endpoint() << std::endl;

    // read header
    size_t header;
    boost::asio::read(
            socket,
            boost::asio::buffer( &header, sizeof(header) )
            );
    std::cout << "body is " << header << " bytes" << std::endl;

    // read body
    boost::asio::streambuf buf;
    const size_t rc = boost::asio::read(
            socket,
            buf.prepare( header )
            );
    buf.commit( header );
    std::cout << "read " << rc << " bytes" << std::endl;

    // deserialize
    std::istream is( &buf );
    boost::archive::text_iarchive ar( is );
    Message msg;
    ar & msg;

    std::cout << msg._a << std::endl;
    std::cout << msg._b << std::endl;
    socket.close();
}
}