#include<iostream>
#include<DemoUtils.h>

#include<string>
#include<string.h>

using namespace std;

const int lineSize = 1024;

int main(int argc, char **argv) {
    vector<string> strVector;
    char *lineStr = new char[lineSize];
    delete lineStr;
    string test;
    if (argc < 2) {
        test = string("TESTARG");
    } else {
        test = string(argv[1]);
    }
    cout << "test String = " << test << endl;
    string::iterator wtf = test.begin();
    for (string::iterator si = test.begin(); si != test.end(); si++) {
        cout << "char at[" << si - test.begin() << "]=\"" << *si << "\"" << endl;
    }
    string testStr = "This is a  test";
    cout << "testStr:" << endl << DemoUtils::showstringchars(testStr);
    int nStrings = DemoUtils::string2vector(testStr, strVector);
    cout << "Found " << nStrings << " strings" << endl;
    cout << "strCount " << strVector.size() << endl;

    cout << DemoUtils::vector2string(strVector);
    return 0;
}
