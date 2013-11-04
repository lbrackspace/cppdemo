#ifndef __LOOKUP_H
#define __LOOKUP_H
#include<boost/asio.hpp>
#include<string>
int usage(char *prog);
boost::shared_ptr<boost::asio::ip::tcp::resolver::iterator> resolveTCP(std::string& host, std::string& service, boost::asio::io_service& ios, boost::system::error_code& ec);
#endif
