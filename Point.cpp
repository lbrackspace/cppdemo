#include<Point.h>
#include<string>
#include<iostream>
#include<sstream>

using namespace std;

Point::Point() {
    cout << "Point() called" << endl;
}

Point::Point(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
    cout << "Point(" << x << "," << y << "," << z << ") called" << endl;
}

Point::Point(const Point& orig) {
    cout << "Point(const Point& orig) called" << endl;
}

Point::~Point() {
    cout << "~Point(" << x << "," << y << "," << z << ") called" << endl;
}

Point Point::operator +(Point& oth) {
    Point out;
    out.x = this->x + oth.x;
    out.y = this->y + oth.y;
    out.z = this->z + oth.z;
    return out;
}

string Point::str() {
    ostringstream os;
    os << "(" << x << "," << y << "," << z << ")";
    return os.str();
}