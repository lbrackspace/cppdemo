#ifndef CMDSERVER_H
#define	CMDSERVER_H

#include<boost/asio.hpp>
#include<boost/thread.hpp>
#include"ring_buffer.h"
using namespace std;
using namespace boost;
using namespace boost::asio;

const int RINGBUFFSIZE = 4096;
const int SOCKBUFFSIZE = 256;

class cmd_server {
private:
    shared_ptr<ip::tcp::socket> socket;
    ring_buffer rb;
public:

    cmd_server() : rb(RINGBUFFSIZE) {
    }

    cmd_server(shared_ptr<ip::tcp::socket> s) : socket(s), rb(RINGBUFFSIZE) {
    }
    cmd_server(const cmd_server& orig);

    void operator()() {
        size_t nBytes;
        char buff[SOCKBUFFSIZE + 1];
        cout << socket->remote_endpoint() << ":Connection accepted";
        boost::system::error_code ec;
        do {
            nBytes = socket->read_some(buffer(buff, SOCKBUFFSIZE), ec);
            if (ec == 0) {
                rb.write(buff, nBytes);
                cout << "thread: " << boost::this_thread::get_id() << " recieved message " << socket->remote_endpoint() << endl;
            }
        } while (ec == 0);
    }

    virtual ~cmd_server() {
    };

};

#endif	/* CMDSERVER_H */

