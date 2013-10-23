#include "DemoUtils.h"

#include<string.h>

#include<string>
#include<sstream>

const int STRBUFFSIZE = 4096;

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

string DemoUtils::showstringchars(string& strIn) {
    ostringstream os;
    const string::iterator beg = strIn.begin();
    const string::iterator end = strIn.end();
    for (string::iterator si = beg; si != end; si++) {
        int i = si - beg;
        os << "str[" << i << "]=\"" << *si << "\"" << endl;
    }
    os << "What the fuck" << endl;
    return os.str();
}

int DemoUtils::string2vector(const string& strIn, vector<string>& strVector) {
    int nStrings = 0;
    const char *strArray = strIn.c_str();
    char buff[STRBUFFSIZE];
    int i = 0;
    int ci = 0;
    int cb = 0;
    int ce = 0;
    int cl;
    int li = strIn.size();
    for (ci = 0; ci < li; ci++) {
        ce = ci;
        cl = ce - cb;
        if (strArray[ci] == '\0') {
            break;
        }
        if (strArray[ci] == ' ' || cl > STRBUFFSIZE + 1) {
            if (cl > 0) {
                for (i = 0; i < cl; i++) {
                    buff[i] = strArray[cb + i];
                }
                buff[cl] = '\0';
                string str = string(buff);
                strVector.push_back(buff);
                cb = ce + 1;
                ci = cb;
                nStrings++;
            }
        }
    }
    return nStrings;
}

string DemoUtils::vector2string(vector<string> &strVector) {
    ostringstream os;
    vector<string>::iterator beg = strVector.begin();
    vector<string>::iterator end = strVector.end();

    os << "Iterating through " << strVector.size() << " strings" << endl;
    for (vector<string>::iterator si = beg; si != end; si++) {
        int entry_i = si - beg;
        os << "strVector[" << entry_i << "]=\"" << *si << "\"" << endl;
    }
    return os.str();
}