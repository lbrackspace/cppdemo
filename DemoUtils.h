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
    static string showstringchars(string& strIn);
    static string args2String(int argc, char **argv);
    static string vector2string(vector<string> &strVector);
    static int string2vector(const string& strIn, vector<string>& strVector);
private:

};

#endif	/* DEMOUTILS_H */

