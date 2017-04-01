#ifndef dcpp_h
#define dcpp_h

#include <boost/asio/basic_seq_packet_socket.hpp>
#include <boost/asio/basic_socket_acceptor.hpp>
#include <boost/asio/seq_packet_socket_service.hpp>
#include <boost/asio/ip/basic_endpoint.hpp>
#include <boost/asio/ip/basic_resolver.hpp>

namespace boost::asio {
namespace ip {

class dccp {
public:
	//! The type of a DCCP endpoint.
	typedef boost::asio::ip::basic_endpoint<dccp> endpoint;

	//! The DCCP socket type.
	typedef boost::asio::basic_seq_packet_socket<dccp> socket;

	//! The DCCP acceptor type.
	typedef boost::asio::basic_socket_acceptor<dccp> acceptor;

	//! The DCCP resolver type.
	typedef boost::asio::ip::basic_resolver<dccp> resolver;

	//! Construct to represent the IPv4 DCCP protocol.
	static dccp v4() {
		return dccp(BOOST_ASIO_OS_DEF(AF_INET));
	}

	//! Construct to represent the IPv6 DCCP protocol.
	static dccp v6() {
		return dccp(BOOST_ASIO_OS_DEF(AF_INET6));
	}

	//! Obtain an identifier for the type of the protocol.
	int type() const {
		return SOCK_DCCP;
	}

	//! Obtain an identifier for the protocol.
	int protocol() const {
		return IPPROTO_DCCP;
	}

	//! Obtain an identifier for the protocol family.
	int family() const {
		return family_;
	}

	//! Compare two protocols for equality.
	friend bool operator==(const dccp& p1, const dccp& p2) {
		return p1.family_ == p2.family_;
	}

	//! Compare two protocols for inequality.
	friend bool operator!=(const dccp& p1, const dccp& p2) {
		return p1.family_ != p2.family_;
	}

private:
	//! Construct with a specific family.
	explicit dccp(int protocol_family) : family_(protocol_family) {
	}

	int family_;
};

} // namespace ip

//! Open a sequenced packet socket.
template <>
inline boost::system::error_code seq_packet_socket_service<ip::dccp>::open(implementation_type& impl, const protocol_type& protocol, boost::system::error_code& ec) {
	if (protocol.type() == SOCK_DCCP)
		service_impl_.open(impl, protocol, ec);
	else
		ec = boost::asio::error::invalid_argument;
	return ec;
}

} // namespace boost::asio

#endif
