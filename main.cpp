#include<iostream>
#include<DemoUtils.h>

#include<exception>
#include<stdexcept>
#include<sstream>
#include<string>
#include<string.h>
#include<cstdlib>
#include<unistd.h>
#include<map>

using namespace std;

const int LINE_SIZE = 1024;

string help() {
    ostringstream os;
    os << "help #Displays this help menu" << endl
            << "pa <args..> #Echo args" << endl
            << "wb <nBytes> #add nBytes to the vector<string> wb object" << endl
            << "fb #Free all bytes in vector<string> wb object" << endl
            << "nwb #Display number of bytes wasted so far" << endl
            << "clearmap #clear map<string,string> strMap object" << endl
            << "put <key> <val> #put the key value in the map<string,string> strMap object" << endl
            << "get <key> #Get value in map map<string,string> strMap object" << endl
            << "keys #List keys in map<string,string> strMap object" << endl
            << "dkey #Delete the key from the map<string,string> strMap object" << endl
            << "ln <nTimes> #Execute loop nTimes" << endl
            << "allmap #Display all key values in map<string,string> strMap object" << endl
            << "nv <double1...double2> #Normalize vector" << endl;
    return os.str();
}

int main(int argc, char **argv) {
    char *cmd = new char[LINE_SIZE + 1];
    int nArgs = 0;
    int i;
    long nwb = 0;
    vector<string> *strVector = new vector<string>;
    map<string, string> *strMap = new map<string, string>;
    string prompt = "Silly Shell> ";
    vector<string>cmdArgs;
    cout << "pid = " << getpid() << endl;
    do {
        try {
            cout << prompt;
            cin.getline(cmd, LINE_SIZE);
            cmdArgs.clear();
            nArgs = DemoUtils::string2vector(cmd, cmdArgs);
            if ((nArgs >= 2) && (cmdArgs[0].compare("wb") == 0)) {
                int nBytes = atoi(cmdArgs[1].c_str());
                if (nBytes <= 0) {
                    cout << "No bytes to waste" << endl;
                }
                cout << "wasting " << nBytes << " bytes" << endl;

                char *tmpBytes = new char[nBytes + 1];
                for (i = 0; i < nBytes; i++) {
                    tmpBytes[i] = ' ';
                }
                tmpBytes[i] = '\0';
                strVector->push_back(tmpBytes);
                nwb += nBytes;
                delete tmpBytes;
            } else if ((nArgs >= 1) && (cmdArgs[0].compare("pa") == 0)) {
                string argStr = DemoUtils::showvector<string > (cmdArgs);
                cout << "args = " << argStr << endl;
            } else if ((nArgs >= 1) && (cmdArgs[0].compare("fb") == 0)) {
                cout << "Freeing " << nwb << " bytes" << endl;
                delete strVector;
                strVector = new vector<string>;
                nwb = 0;
            } else if ((nArgs >= 2) && (cmdArgs[0].compare("nv") == 0)) {
                vector<double> dvector;
                cout << "Converting strings to double" << endl;
                for (i = 1; i < nArgs; i++) {
                    double val = std::atof(cmdArgs[i].c_str());
                    dvector.push_back(val);
                }
                cout << "vector<double> vals = " << DemoUtils::showvector<double>(dvector) << endl;
                cout << "Normalizing" << endl;
                DemoUtils::normalize(dvector);
                cout << DemoUtils::showvector<double>(dvector) << endl;
            } else if ((nArgs >= 1) && (cmdArgs[0].compare("nwb") == 0)) {
                long wasted_size = 0;
                for (vector<string>::iterator si = strVector->begin(); si != strVector->end(); si++) {
                    wasted_size += strlen(si->c_str());
                }
                cout << "bytes wasted so far is " << nwb << "= " << wasted_size << endl;

            } else if ((nArgs >= 1) && (cmdArgs[0].compare("help") == 0)) {
                cout << help() << endl;
            } else if (nArgs >= 1 && (cmdArgs[0].compare("clearmap") == 0)) {
                delete strMap;
                strMap = new map<string, string>;
            } else if (nArgs >= 3 && (cmdArgs[0].compare("put") == 0)) {
                string key = cmdArgs[1];
                string val = cmdArgs[2];
                cout << "setting map[" << key << "]=" << val << endl;
                strMap->insert(make_pair(key, val));
            } else if (nArgs >= 2 && (cmdArgs[0].compare("get") == 0)) {
                string key = cmdArgs[1];
                cout << "getting map[" << key << "]=";
                string val;
                try {
                    val = strMap->at(key);
                } catch (out_of_range& ex) {
                    val = "null";
                }
                cout << val << endl;
            } else if (nArgs >= 1 && (cmdArgs[0].compare("keys") == 0)) {
                cout << "{";
                map<string, string>::iterator beg = strMap->begin();
                map<string, string>::iterator end = strMap->end();

                for (map<string, string>::iterator ki = beg; ki != end; ki++) {
                    string key = ki->first;
                    cout << "\"" << key << "\", ";
                }
                cout << "}" << endl;
            } else if (nArgs >= 1 && (cmdArgs[0].compare("allmap") == 0)) {
                map<string, string>::iterator beg = strMap->begin();
                map<string, string>::iterator end = strMap->end();
                cout << "{";
                for (map<string, string>::iterator mi = beg; mi != end; mi++) {
                    string key = mi->first;
                    string val = mi->second;
                    cout << "(\"" << key << "\",\"" << val << "\"), ";
                }
                cout << "}" << endl;

            } else if ((nArgs >= 2) && (cmdArgs[0].compare("dkey") == 0)) {
                string key = cmdArgs[1];
                cout << "deleting key " << key << endl;
                strMap->erase(key);
            } else if ((nArgs >= 2) && (cmdArgs[0].compare("ln") == 0)) {
                int nTimes = atoi(cmdArgs[1].c_str());
                cout << "Looping " << nTimes << endl;
                double beforeTime = DemoUtils::gettimevalue();
                vector<string> tmpV;
                for (i = 0; i < nTimes; i++) {
                    tmpV.clear();
                    int nVecs = DemoUtils::string2vector(string("This is a xxxx  x  x xxx xxxx xxxx xxx xxx xxx    test"), tmpV);
                }
                double afterTime = DemoUtils::gettimevalue();
                double timeDelta = afterTime - beforeTime;
                cout << "looped " << nTimes << " in " << timeDelta << " seconds" << endl;
            } else {
                cout << "Unknown command" << cmd << endl;
                cout << help() << endl;
            }
        } catch (exception& ex) {
            cout << "exception:" << ex.what() << endl;
        }
    } while (!cin.eof());
    delete strVector;
    delete strMap;
    return 0;
}
