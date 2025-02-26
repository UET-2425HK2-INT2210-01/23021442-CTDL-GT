#include <iostream>
#include <iomanip>
using namespace std;

class Point {
public:
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

class Line {
public:
    Point p1, p2;
    Line(Point p1, Point p2) : p1(p1), p2(p2) {}
};

Point getIntersection(Line l1, Line l2) {
    double a1 = l1.p2.y - l1.p1.y;
    double b1 = l1.p1.x - l1.p2.x;
    double c1 = a1 * l1.p1.x + b1 * l1.p1.y;

    double a2 = l2.p2.y - l2.p1.y;
    double b2 = l2.p1.x - l2.p2.x;
    double c2 = a2 * l2.p1.x + b2 * l2.p1.y;

    double determinant = a1 * b2 - a2 * b1;

    if (determinant == 0) {
        if (a1 * l2.p1.x + b1 * l2.p1.y == c1 && a2 * l1.p1.x + b2 * l1.p1.y == c2) {
            throw "MANY";
        }
        throw "NO";
    }

    double x = (b2 * c1 - b1 * c2) / determinant;
    double y = (a1 * c2 - a2 * c1) / determinant;
    return Point(x, y);
}

int main() {
    Point A, B, C, D;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    cin >> D.x >> D.y;

    Line AB(A, B);
    Line CD(C, D);

    try {
        Point intersection = getIntersection(AB, CD);
        cout << fixed << setprecision(2);
        cout << intersection.x << " " << intersection.y << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    }

    return 0;
}
