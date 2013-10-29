#include<iostream>
#include<DemoUtils.h>
#include<ThreadManager.h>
#include<Matrix.h>
#include<Point.h>
#include<boost/thread.hpp>
#include<exception>
#include<stdexcept>
#include<sstream>
#include<ostream>
#include<string>
#include<string.h>
#include<cstdlib>
#include<unistd.h>
#include<map>

using namespace std;

const int LINE_SIZE = 1024;
Point getPoint(vector<string> args, int offset);
string showsizeof();
string help();

int main(int argc, char **argv) {
    char *cmd = new char[LINE_SIZE + 1];
    int nArgs = 0;
    int i;
    long nwb = 0;
    Point p1;
    Point p2;
    Point sum;
    vector<string> *strVector = new vector<string>;
    map<string, string> *strMap = new map<string, string>;
    vector<Matrix>matVector;
    string prompt = "Silly Shell> ";
    ThreadManager tm(cout);
    vector<string>cmdArgs;
    cout << "pid = " << getpid() << endl;
    cout << "main thread_id = " << boost::this_thread::get_id() << endl;
    do {
        try {
            cout << prompt;
            cin.getline(cmd, LINE_SIZE);
            cmdArgs.clear();
            nArgs = DemoUtils::string2vector(cmd, cmdArgs, ' ');
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
                vector<string>::iterator si;
                vector<string>::iterator beg = strVector->begin();
                vector<string>::iterator end = strVector->end();
                for (si = beg; si != end; si++) {
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
            } else if ((nArgs >= 2) && (cmdArgs[0].compare("avg") == 0)) {
                vector<double> dvector;
                cout << "Converting strings to double" << endl;
                for (i = 1; i < nArgs; i++) {
                    double val = std::atof(cmdArgs[i].c_str());
                    dvector.push_back(val);
                }
                cout << "vector<double> vals = " << DemoUtils::showvector<double>(dvector) << endl;
                double avg = DemoUtils::avg(dvector);
                cout << "abg = " << avg << endl;

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
                map<string, string>::iterator ki;
                map<string, string>::iterator beg = strMap->begin();
                map<string, string>::iterator end = strMap->end();

                for (ki = beg; ki != end; ki++) {
                    string key = ki->first;
                    cout << "\"" << key << "\", ";
                }
                cout << "}" << endl;
            } else if (nArgs >= 1 && (cmdArgs[0].compare("allmap") == 0)) {
                map<string, string>::iterator mi;
                map<string, string>::iterator beg = strMap->begin();
                map<string, string>::iterator end = strMap->end();
                cout << "{";
                for (mi = beg; mi != end; mi++) {
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
                    string testString("This is a xxxx  x  x xxx xxxx xxxx xxx xxx xxx    test");
                    int nVecs = DemoUtils::string2vector(testString, tmpV, ' ');
                }
                double afterTime = DemoUtils::gettimevalue();
                double timeDelta = afterTime - beforeTime;
                cout << "looped " << nTimes << " in " << timeDelta << " seconds" << endl;
            } else if ((nArgs >= 1) && cmdArgs[0].compare("st") == 0) {
                cout << "Showing running threads" << endl;
                cout << tm.to_string() << endl;
            } else if ((nArgs >= 1) && cmdArgs[0].compare("jt") == 0) {
                cout << "joining threads" << endl;
                tm.joinThreads();
                cout << "All threads joined" << endl;
            } else if ((nArgs >= 4) && cmdArgs[0].compare("nt") == 0) {
                int nThreads = std::atoi(cmdArgs[1].c_str());
                int nSecs = std::atoi(cmdArgs[2].c_str());
                int nTimes = std::atoi(cmdArgs[3].c_str());
                cout << "creating " << nThreads << " that will sleep for " << nSecs << " seconds " << nTimes << " times" << endl;
                for (i = 0; i < nThreads; i++) {
                    cout << "creating thread " << i << " of " << nThreads << endl;
                    tm.newThread(nSecs, nTimes);
                }
                cout << "All threads spawned" << endl;
            } else if ((nArgs >= 1) && cmdArgs[0].compare("sizeof") == 0) {
                cout << showsizeof() << endl;
            } else if ((nArgs >= 1) && cmdArgs[0].compare("mf") == 0) {
                cout << "Clearing " << matVector.size() << " entries from matrix vector" << endl;
                matVector.clear();
            } else if ((nArgs >= 7) && cmdArgs[0].compare("ap") == 0) {
                p1 = getPoint(cmdArgs, 1);
                p2 = getPoint(cmdArgs, 4);
                sum = p1 + p2;
                cout << "Sum of " << p1.str() << " + " << p2.str() << " = " << sum.str() << endl;
            } else if ((nArgs >= 2) && cmdArgs[0].compare("ma") == 0) {
                int nMatrixes = std::atoi(cmdArgs[1].c_str());
                cout << "Adding " << nMatrixes << " 100x100 matrixes" << endl;
                for (i = 0; i < nMatrixes; i++) {
                    matVector.push_back(Matrix(100, 100));
                }
            } else {
                cout << "Unknown command" << cmd << endl;
                cout << help() << endl;
            }
        } catch (std::exception& ex) {
            cout << "exception:" << ex.what() << endl;
        }
    } while (!cin.eof());
    delete strVector;
    delete strMap;
    delete cmd;
    return 0;
}

Point getPoint(vector<string> args, int offset) {
    double x = std::atof(args[offset + 0].c_str());
    double y = std::atof(args[offset + 1].c_str());
    double z = std::atof(args[offset + 2].c_str());
    Point p = Point(x, y, z);
    return p;
}

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
            << "nv <double1...double> #Normalize vector" << endl
            << "avg <double1...double> #compute Average vector" << endl
            << "st #Show running threads" << endl
            << "jt #Join running threads" << endl
            << "nt <nThreads> <nSecs> <nTimes> #Spawn nThreads with each one sleeping for nSecs nTimes" << endl
            << "sizeof #Get size of varias data types" << endl
            << "ma <nEntries> # Add n 100x100 matrixes into memory" << endl
            << "mf #Free matrixes from memory" << endl
            << "ap <x1> <y1> <z1> <x2> <y2> <z2> #Add the two points together" << endl
            << "dp <x1> <y1> <z1> <x2> <y2> <z2> #Dot the two points together" << endl;
    return os.str();
}

string showsizeof() {
    ostringstream os;
    os << "Sizeof:" << endl
            << "sizeof(char):             " << setw(4) << sizeof (char) << endl
            << "sizeof(int):              " << setw(4) << sizeof (int) << endl
            << "sizeof(long):             " << setw(4) << sizeof (long) << endl
            << "sizeof(long long):        " << setw(4) << sizeof (long) << endl
            << "sizeof(float):            " << setw(4) << sizeof (float) << endl
            << "sizeof(double):           " << setw(4) << sizeof (double) << endl
            << "sizeof(long double):      " << setw(4) << sizeof (long double) << endl
            << "sizeof(void *):           " << setw(4) << sizeof (void *) << endl
            << "sizeof(string):           " << setw(4) << sizeof (string) << endl
            << "sizeof(boost::thread):    " << setw(4) << sizeof (boost::thread) << endl
            << "sizeof(ThreadManager):    " << setw(4) << sizeof (ThreadManager) << endl
            << "sizeof(Matrix):           " << setw(4) << sizeof (Matrix) << endl
            << "sizeof(vector<double>):   " << setw(4) << sizeof (vector<double>) << endl
            << "sizeof(vector<double *>): " << setw(4) << sizeof (vector<double *>) << endl;
    return os.str();
}