#include<iostream>
#include<boost/asio.hpp>


using namespace std;
using namespace boost;

int usage(char *prog) {
    cout << "usage is " << prog << " <ip> <port>" << endl;
    cout << endl;
    cout << "Spawns off a threaded servicer that echos back commands" << endl;
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        usage(argv[0]);
        return -1;
    }
    string ip_addr_str(argv[1]);
    string port_addr_str(argv[2]);
    cout << "Listening to ip " << ip_addr_str << " on port " << port_addr_str << endl;

}
