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
    static string args2String(int argc, char **argv);
    static vector<string> splitString2vector(string strIn);
private:

};

#endif	/* DEMOUTILS_H */

