#include <bits/stdc++.h>
using namespace std;

#define LONG_DOUBLE_TYPE long double

typedef complex<double> Point;

namespace std {
    bool operator<(Point p, Point q) {
        if (real(p) != real(q)) return real(p) < real(q);
        return imag(p) < imag(q);
    }
};

double dotProduct(Point p, Point q) { return real(conj(p) * q); }
double crossProduct(Point p, Point q) { return imag(conj(p) * q); }
double EPSILON = 1e-8;

int getSign(double x) {
    if (x < 0) return -1;
    if (x > +EPSILON) return +1;
    return 0;
}

struct Circle {
    Point center;
    double radius;
};

struct Line {
    Point startPoint, endPoint;

    double square(double x) {
        return x * x;
    }

    double getLength() {
        return sqrt(square(real(startPoint) - real(endPoint)) + square(imag(startPoint) - imag(endPoint)));
    }

    double getLengthSquared() {
        return square(real(startPoint) - real(endPoint)) + square(imag(startPoint) - imag(endPoint));
    }
};

vector<Point> findIntersectionPoints(Line line, Circle circle) {
    Point u = line.startPoint - line.endPoint, v = line.startPoint - circle.center;
    double a = norm(u), b = dotProduct(u, v), c = norm(v), det = b * b - a * c, r = b + sqrt(max(det, (double)0.0));
    if (getSign(det) < 0) return {};
    return { line.startPoint - (b + sqrt(det)) / a * u, line.startPoint - c / (b + sqrt(det)) * u };
}

template<class Function>
double ternarySearch(double start, double end, Function f) {
    assert(start <= end);
    while (end - start >= 1e-14) {
        double mid1 = start + (end - start) / 3;
        double mid2 = start + (end - start) * 2 / 3;
        if (f(mid1) > f(mid2)) start = mid1;
        else end = mid2;
    }
    return f(start);
}


double PI = acos(-1.0);

double findMinimumAngle(double start, double end, Circle circle, Point pointA, Point pointB) {
    if (end < start) swap(start, end);
    return ternarySearch(start, end, [&](double phi){
        double X = real(circle.center) + circle.radius * cos(phi);
        double Y = imag(circle.center) + circle.radius * sin(phi);
        Line lineAtoE = { pointA, { X, Y } };
        Line lineBtoE = { pointB, { X, Y } };
        return lineAtoE.getLength() + lineBtoE.getLength();
    });
}

bool isPointInsideCircle(Point point, Line line) {
    double D = dotProduct(point - line.startPoint, line.endPoint - line.startPoint);
    if (D < 0 || norm(point - line.startPoint) > norm(line.endPoint - line.startPoint)) return false;
    return true;
}

void solve() {
    double Ax, Ay, Bx, By, Cx, Cy, R;
    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> R;

    if (Ax == Bx && Ay == By) Bx += 1e-10;

    Point pointA = { Ax, Ay };
    Point pointB = { Bx, By };
    Point pointC = { Cx, Cy };
    Circle circleC = { pointC, R };
    Line lineAB = { pointA, pointB };

    double distanceAtoC = Line{ pointA, pointC }.getLengthSquared();
    double distanceBtoC = Line{ pointB, pointC }.getLengthSquared();
    
    auto intersectionPoints = findIntersectionPoints(lineAB, circleC);
    bool areInside = false;

    for (auto intersectionPoint : intersectionPoints) {
        if (isPointInsideCircle(intersectionPoint, lineAB)) {
            areInside = true;
        }
    }

    if (areInside || (distanceAtoC <= R * R && distanceBtoC <= R * R)) {
        cout << fixed << setprecision(16) << lineAB.getLength() << endl;
    } else {
        Point vectorAB = pointB - pointA;
        double phi_start = acos(real(vectorAB) / sqrt(norm(vectorAB)));
        double ans1 = findMinimumAngle(phi_start, phi_start + PI, circleC, pointA, pointB);
        double ans2 = findMinimumAngle(phi_start, phi_start - PI, circleC, pointA, pointB);
        cout << fixed << setprecision(16) << min(ans1, ans2) << endl;
    }
}

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}
