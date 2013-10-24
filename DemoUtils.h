#ifndef DEMOUTILS_H
#define	DEMOUTILS_H

#include<string>
#include<vector>
#include<sstream>

using namespace std;

class DemoUtils {
public:
    DemoUtils();
    DemoUtils(const DemoUtils& orig);
    virtual ~DemoUtils();
    static string showstringchars(const string& strIn);
    static string args2String(int argc, char **argv);
    static string vector2string(const vector<string> &strVector);
    static int string2vector(const string& strIn, vector<string>& strVector);
    static string showstringvector(const vector<string> &strVector);

    template<typename T> static string showvector(const vector<T>& v) {
        ostringstream os;
        const typename vector<T>::const_iterator beg = v.begin();
        const typename vector<T>::const_iterator end = v.end();
        os << "{";
        for (typename vector<T>::const_iterator vi = beg; vi != end; vi++) {
            os << *vi;
            if (end - 1 > vi) {
                os << ", ";
            }
        }
        os << "}";
        return os.str();
    }
    static double gettimevalue();
    static void normalize(vector<double> &v);
private:

};

#endif	/* DEMOUTILS_H */

