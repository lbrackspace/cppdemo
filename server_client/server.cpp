#include<iostream>

#include<boost/asio.hpp>
#include<boost/thread.hpp>
using namespace std;

int usage(char * prog) {
    cout << "Usage is " << prog << "<ip> <port>" << endl;
}

void client_session(boost::shared_ptr<boost::asio::ip::tcp::socket> sock) {
    char data[4096];
    while (true) {
        size_t len = sock->read_some(boost::asio::buffer(data));
        if (len > 0) write(*sock, boost::asio::buffer("OK", 2));
    }
}


int main(int argc, char **argv) {
    if (argc < 3) {
        usage(argv[0]);
        return 0;
    }
    cout << "Starting server at address " << argv[1] << " port " << argv[2] << endl;

    return 0;
}
