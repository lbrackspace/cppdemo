#ifndef DEMOUTILS_H
#define	DEMOUTILS_H

#include<string>
#include<vector>

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
    
    static double gettimevalue();
    static void normalize(vector<double> &v);
private:

};

#endif	/* DEMOUTILS_H */

