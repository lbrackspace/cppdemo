#include<iostream>
#include<boost/asio.hpp>
#include<boost/asio/ip/address.hpp>
#include<boost/shared_ptr.hpp>
#include"lookup.h"


using namespace std;
using namespace boost;
using namespace boost::asio;

int main(int argc, char **argv) {
    if (argc < 3) {
        usage(argv[0]);
        return 0;
    }
    string host(argv[1]);
    string service(argv[2]);
    cout << "looking up host " << host << endl;
    boost::system::error_code ec;
    io_service ios;
    boost::shared_ptr<ip::tcp::resolver::iterator> it = resolveTCP(host, service, ios, ec);
    if (ec) {
        cout << "Error resolving host:" << host << endl;
        return 0;
    }
    ip::tcp::resolver::iterator end;
    while (*it != end) {
        cout << (*it)->endpoint() << endl;
        (*it)++;
    }
    return 0;
}

boost::shared_ptr<ip::tcp::resolver::iterator> resolveTCP(string& host, string& service, io_service& ios, boost::system::error_code& ec) {
    ip::tcp::resolver r(ios);
    ip::tcp::resolver::query q(host, service);
    boost::shared_ptr<ip::tcp::resolver::iterator> it(new ip::tcp::resolver::iterator(r.resolve(q, ec)));
    if (ec) {
        boost::shared_ptr<ip::tcp::resolver::iterator> null;
        return null;
    }
    //ip::tcp::resolver::iterator it = r.resolve(q, ec);
    cout << "it @" << it.get() << endl;
    return it;
}

int usage(char *prog) {
    cout << "usage is " << prog << " <hostname> <port>" << endl;
    cout << endl;
    cout << "Lookup the ip address of host machine" << endl;
    return 0;
}
