#include <boost/test/included/unit_test.hpp>

#include "dccp.h++"

using namespace boost::asio;
using namespace ip;
using namespace std;

BOOST_AUTO_TEST_CASE(create_dccp_server_v4) {
	io_service service;
	dccp::acceptor acceptor(service, dccp::endpoint(dccp::v4(), 0));

	BOOST_TEST(acceptor.local_endpoint().port() > 0);
}

BOOST_AUTO_TEST_CASE(create_dccp_server_v6) {
	io_service service;
	dccp::acceptor acceptor(service, dccp::endpoint(dccp::v6(), 0));

	BOOST_TEST(acceptor.local_endpoint().port() > 0);
}

BOOST_AUTO_TEST_CASE(socket_test) {
	io_service service;
	dccp::acceptor server(service, dccp::endpoint(dccp::v4(), 0));
    BOOST_TEST(server.local_endpoint().port() > 0);

    dccp::socket client_con(service);
	server.async_accept(client_con, [&](auto err){
		BOOST_TEST(!err);

		socket_base::message_flags flags;
		client_con.async_send(buffer("hello world"), flags, [](auto err, auto bytes){
			BOOST_TEST(!err);
			BOOST_TEST(bytes == 12);
		});
	});

    dccp::socket client(service);
    client.async_connect(server.local_endpoint(), [&](auto err){
        BOOST_TEST(!err);

        array<char, 1024> received;
        socket_base::message_flags flags;
        client.async_receive(buffer(received), flags, [&](auto err, auto bytes){
            BOOST_TEST(!err);
            BOOST_TEST(bytes == 12);
            BOOST_TEST(string("hello world").compare(received.data()));
        });
    });

    service.run();
}
