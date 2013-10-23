#include "DemoUtils.h"

#include<string>
#include<sstream>
using namespace std;

DemoUtils::DemoUtils() {
}

DemoUtils::DemoUtils(const DemoUtils& orig) {
}

DemoUtils::~DemoUtils() {
}

string DemoUtils::args2String(int argc, char** argv) {
    ostringstream os;
    for (int i = 0; i < argc; i++) {
        os << "argv[" << i << "]=" << argv[i] << endl;
    }
    return os.str();
}

vector<string> DemoUtils::splitString2vector(string strIn){

}