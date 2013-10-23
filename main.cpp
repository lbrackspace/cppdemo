#include<iostream>
#include<DemoUtils.h>
using namespace std;

const int lineSize = 1024;

int main(int argc, char **argv) {
    char *lineStr = new char[lineSize];
    delete lineStr;
    return 0;
}
